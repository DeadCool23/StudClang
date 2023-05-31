#!/bin/bash

# Проверка введенного аргумента
if [ $# -ne 1 ] || [[ ! "$1" =~ ^[0-9]+$ ]]; then
    N=10005
else
    N=$1
fi


IFS=' ' read -ra optimizations <<< "$(cat data/optimizations)" # Получение измеряемых оптимизаций
mapfile -t arrs_type < <(ls data/arrs) # Получение измеряемых типов массивов

# Удаление исполняемых файлов при их наличии
if [[ -n "$(ls ../apps)" ]]; then
    rm ../apps/*.exe
fi

# Создание массива общих исходных кодов
libs="../progs/libs/*.c"
lib_files=()
for lib in $libs; do
    lib_files+=("$lib")
done

compile_keys=("-std=c99" "-Wall" "-Werror" "-Wpedantic" "-Wextra" "-Wvla" "-Wfloat-equal" "-Wfloat-conversion" "-lm") # Ключи компиляции
arr_type_def=("RAND" "SORT") # Типы массивов

progs="../progs/*.c" # Программы с разными способами обращения к элементам массива
for prog in $progs; do
    # Получение  названия способа обращения к элементам массива
    prog_name=$(basename "${prog}")
    prog_name="${prog_name%%.c}"
    for i in "${!arrs_type[@]}"; do
        for j in "${!optimizations[@]}"; do
            app="../apps/""$prog_name""_${optimizations[$j]}_${arrs_type[$i]}.exe" # Создание нзвания исполняемого файла
            gcc "$prog" "${lib_files[@]}" -"${optimizations[$j]}" -DN="$N" -D"${arr_type_def[$i]}" "${compile_keys[@]}" -o "$app" # Компиляция
        done
    done
done

echo -e "\e[1;32mApps are created\e[0m"
