#!/bin/bash

progs="../progs/*.c"
opts=$(cat data/optimizations)
arr_types=$(ls data/arrs)

echo "0" > ../measures/runs.txt
for prog in $progs; do
    for arr_type in $arr_types; do
        prog="${prog%%.c}"
        prog="${prog##../progs/}"
        for opt in $opts; do
            rm ../measures/"$prog"/"$arr_type"/"$opt"/*.txt
        done
    done
done

echo -e "\e[1;32mMeasures successfully deleted\e[0m"
