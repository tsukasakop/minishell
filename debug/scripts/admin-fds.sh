#!/bin/bash

assert-pid()
{
    PID="$1"

    if [ -z "$PID" ]; then
        echo 'USAGE:' >&2
        echo "  $0 \$pid" >&2
        echo 'you can get pid by command below (DO ON THE PROCESS to get pid!):' >&2
        echo '  echo $$' >&2
        exit 1
    fi
}

assert-pid "$1"
DIR="${0%/*}"
watch -n 0.2 -d -t "$DIR/show-proc-info.sh" "$1"
