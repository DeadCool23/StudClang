#!/bin/bash

labs="lab_*"

for lab in $labs; do
    tasks="$lab""/lab_*"
    for task in $tasks; do
        rm -f "$task"/*.sh
        rm -f "$task"/func_tests/scripts/*_case.sh
        rm -f "$task"/func_tests/scripts/*_tests.sh
    done
done
