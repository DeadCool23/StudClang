#!/bin/bash

if [ $# -ne 1 ] || [[ ! "$1" =~ ^[0-9]+$ ]]; then
    N=10005
else
    N=$1
fi

IFS=' ' read -ra optimizations <<< "$(cat data/optimizations)"
mapfile -t arrs_type < <(ls data/arrs)

if [[ -n "$(ls ../apps)" ]]; then
    rm ../apps/*.exe
fi

libs="../progs/libs/*.c"
lib_files=()
for lib in $libs; do
    lib_files+=("$lib")
done

compile_keys=("-std=c99" "-Wall" "-Werror" "-Wpedantic" "-Wextra" "-Wvla" "-Wfloat-equal" "-Wfloat-conversion" "-lm")
arr_type_def=("RAND" "SORT")

progs="../progs/*.c"
for prog in $progs; do
    prog_name=$(basename "${prog}")
    prog_name="${prog_name%%.c}"
    for i in "${!arrs_type[@]}"; do
        for j in "${!optimizations[@]}"; do
            app="../apps/""$prog_name""_${optimizations[$j]}_${arrs_type[$i]}.exe"
            gcc "$prog" "${lib_files[@]}" -"${optimizations[$j]}" -DN="$N" -D"${arr_type_def[$i]}" "${compile_keys[@]}" -o "$app"
        done
    done
done

echo -e "\e[1;32mApps are created\e[0m"
