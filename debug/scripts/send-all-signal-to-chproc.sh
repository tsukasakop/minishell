#!/bin/bash

set -x
for sig in {0..31}; do
    sleep $(($sig + 1000)) &
    kill -$sig $!
done
sleep 1000
