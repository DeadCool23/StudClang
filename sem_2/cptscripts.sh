#!/bin/bash

labs="lab_*"

for lab in $labs; do
    tasks="$lab""/lab_*"
    for task in $tasks; do
        cp tscripts/*.sh "$task" 2> /dev/null
        cp tscripts/func_tests/scripts/*.sh "$task"/func_tests/scripts 2> /dev/null
    done
done
