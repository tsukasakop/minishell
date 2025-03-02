#!/usr/bin/perl

use strict;
use warnings;

# Match function prototypes from definitions
foreach my $filename (@ARGV) {
    open my $fh, '<', $filename or die "Cannot open $filename: $!";
    local $/ = undef;
    my $file = <$fh>;
    close $fh;

    while ($file =~ /
        ^                    # Allow leading spaces
        \w+(?:\ \w+)*        # Match additional keywords (e.g., `unsigned char`)
        \t                   # Match space(s) before function name
        \**                  # Match pointers (`*`, `**`)
        \w+                  # Match function name
        \(.*?\)               # Capture function parameters
        (?=\n\{)             # Ensure it's followed by `{` (but don't include it)
    /xmsg)
    {
        print "$&;\n";  # Output the function prototype with `;`
    }
}
