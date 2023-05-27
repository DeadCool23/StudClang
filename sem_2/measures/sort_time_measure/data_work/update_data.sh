#!/bin/bash

if [[ "$1" =~ ^[0-9]+$ ]]; then
    runs=$1
else
    runs=10
fi

was_runed="$(cat ../measures/runs.txt)"
is_runed=$((was_runed+runs))
echo "$is_runed" > ../measures/runs.txt 

rm -fr ../measures/*
touch ../measures/runs.txt
echo "$runs" > ../measures/runs.txt 

progs="../progs/*.c"
opts=$(cat data/optimizations)
arr_types=$(ls data/arrs)

for prog in $progs; do
    prog="${prog%%.c}"
    prog="${prog##../progs/}"
    if ! [ -d ../measures/"$prog" ]; then
        mkdir ../measures/"$prog"
    fi
    for arr_type in $arr_types; do
        if ! [ -d ../measures/"$prog"/"$arr_type" ]; then
            mkdir ../measures/"$prog"/"$arr_type"
        fi
        readarray -t arrs <<< "$(cat data/arrs/"$arr_type")"
        for opt in $opts; do
            if ! [ -d ../measures/"$prog"/"$arr_type"/"$opt" ]; then
                mkdir ../measures/"$prog"/"$arr_type"/"$opt"
            fi
            for num in "${!arrs[@]}";do
                i=0
                while [ "$i" -lt "$runs" ]; do
                    ../apps/"$prog"_"$opt"_"$arr_type".exe "${arrs[num]}" >> ../measures/"$prog"/"$arr_type"/"$opt"/"${arrs[num]}".txt
                    i=$((i+1))
                done
            done
            echo -e "\e[1;32mUpdated measures for ""$prog""_""$opt""_""$arr_type""\e[0m"
        done
    done
done

echo -e "\e[1;32mMeasures successfully updated\e[0m"
