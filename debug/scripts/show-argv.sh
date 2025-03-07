#!/usr/bin/env bash

CNT=1
for i in "$@"; do
    echo "argv[$CNT]: \"$i\""
    CNT="$(expr "$CNT" + 1)"
done
unset CNT
