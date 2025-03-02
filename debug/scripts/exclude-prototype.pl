#!/usr/bin/perl

use strict;
use warnings;

# Match function prototypes from definitions
foreach my $filename (@ARGV) {
    open my $fh, '<', $filename or die "Cannot open $filename: $!";
    local $/ = undef;
    my $file = <$fh>;
    close $fh;

    my @prototypes;
    $file =~ s/
        ^                    # Allow leading spaces
        (?:\w+(?:\ \w+)*)    # Match additional keywords (e.g., `unsigned char`)
        \t+                  # Match space(s) before function name
        \**                  # Match pointers (`*`, `**`)
        \w+                  # Match function name
        \([\s\S]*?\)               # Capture function parameters
        ;\n                  # Ensure it's followed by `{` (but don't include it)
    //xmg;
    print "$file\n";
}
