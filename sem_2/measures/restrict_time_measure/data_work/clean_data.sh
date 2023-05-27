#!/bin/bash

progs="../progs/*.c"
opts=$(cat data/optimizations)

echo "0" > ../measures/runs.txt
for prog in $progs; do
    prog="${prog%%.c}"
    prog="${prog##../progs/}"
    for opt in $opts; do
        rm ../measures/"$prog"/"$opt"/*.txt
    done
done

echo -e "\e[1;32mMeasures successfully deleted\e[0m"
