#!/bin/bash

SIG="${1:-SIGINT}"
trap "" "$SIG"
echo "ignoring $SIG."
echo "to kill me, type 'kill -SIGKILL $$'."

while true; do
    help >/dev/null
done
