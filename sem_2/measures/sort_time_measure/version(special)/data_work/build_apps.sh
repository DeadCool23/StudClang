#!/bin/bash

IFS=' ' read -ra optimizations <<< "$(cat data/optimizations)"
mapfile -t arrs_type < <(ls data/arrs)

if [[ -n "$(ls ../apps)" ]]; then
    rm ../apps/*.exe
fi

compile_keys=("-std=c99" "-Wall" "-Werror" "-Wpedantic" "-Wextra" "-Wvla" "-Wfloat-equal" "-Wfloat-conversion" "-lm")

progs="../progs/*.c"
for prog in $progs; do
    prog_name=$(basename "${prog}")
    prog_name="${prog_name%%.c}"
    for i in "${!arrs_type[@]}"; do
        readarray -t arrs <<< "$(cat data/arrs/"${arrs_type[$i]}")"
        for k in "${!arrs[@]}"; do
            arr_inf="${arrs[$k]}"
            arr_len=$(echo "$arr_inf" | grep -E -o "[0-9]*\|" | grep -E -o "[0-9]*")
            arr=$(echo "$arr_inf" | grep -E -o "\|[0-9].*" | grep -E -o "[0-9].*")
            sed -i "s/int arr\[\] = {};/int arr\[\] = { $arr };/" "$prog"
            for j in "${!optimizations[@]}"; do
                app="../apps/""$prog_name""_${optimizations[$j]}_${arrs_type[$i]}_len$arr_len.exe"
                gcc "$prog" -"${optimizations[$j]}" "${compile_keys[@]}" -o "$app"
            done
            sed -i "s/int arr\[\] = { $arr };/int arr\[\] = {};/" "$prog"
        done
    done
done

echo -e "\e[1;32mApps are created\e[0m"
