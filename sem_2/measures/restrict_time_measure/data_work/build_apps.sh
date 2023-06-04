#!/bin/bash

# Проверка введенного аргумента
if [ $# -ne 1 ] || [[ ! "$1" =~ ^[0-9]+$ ]]; then
    N=1000
else
    N=$1
fi

compile_keys=("-std=c99" "-Wall" "-Werror" "-Wpedantic" "-Wextra" "-Wvla" "-Wfloat-equal" "-Wfloat-conversion" "-lm")
optimizations="$(cat data/optimizations)"

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

progs="../progs/*.c"
for prog in $progs; do
    # Программы с разной обработкой элементов матрицы
    prog_name=$(basename "${prog}")
    prog_name="${prog_name%%.c}"
    # Проход по всем оптимизациям
    for optimization in $optimizations; do
        app="../apps/""$prog_name""_""$optimization"".exe" # Создание нзвания исполняемого файла
        gcc "${lib_files[@]}" "$prog" -DN="$N"  -"$optimization" "${compile_keys[@]}" -o "$app"  # Компиляция
    done
done

echo -e "\e[1;32mApps are created\e[0m"
