#!/bin/bash

if [[ "$1" =~ ^[0-9]+$ ]]; then
    runs=$1
else
    runs=10
fi

rm -fr ../measures/*
touch ../measures/runs.txt
echo "$runs" > ../measures/runs.txt 

progs="index_sort adress_sort pointer_sort"
opts=$(cat data/optimizations)
arrs=$(ls data/arrs)

for prog in $progs; do
    mkdir ../measures/"$prog"
    for arr in $arrs; do
        mkdir ../measures/"$prog"/"$arr"
        for opt in $opts; do
            mkdir ../measures/"$prog"/"$arr"/"$opt"
            exe_names=$(ls ../apps/"$prog"_"$opt"_"$arr"*)
            for exe_name in $exe_names; do
                len="$(echo "$exe_name" | grep -E -o "len[0-9]*" | grep -E -o "[0-9]*")"
                i=0
                echo -n "" > ../measures/"$prog"/"$arr"/"$opt"/"$len".txt
                while [ "$i" -lt "$runs" ]; do
                    ../apps/"$prog"_"$opt"_"$arr"_len"$len".exe >> ../measures/"$prog"/"$arr"/"$opt"/"$len".txt
				i=$((i+1))
			    done
            done
        done
    done
done

echo -e "\e[1;32mMeasures successfully updated\e[0m"
