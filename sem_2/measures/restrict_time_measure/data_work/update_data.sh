#!/bin/bash

# Проверка введенного аргумента
if [ $# -ne 1 ] || [[ ! "$1" =~ ^[0-9]+$ ]]; then
    runs=100
else
    runs=$1
fi

# Подсчет кол-ва замеров
was_runed="$(cat ../measures/runs.txt)"
is_runed=$((was_runed+runs))
echo "$is_runed" > ../measures/runs.txt 

progs="../progs/*.c"
opts=$(cat data/optimizations)
readarray -t matrix_sizes <<< "$(cat data/matrix_sizes)"

# Проход по прграммам
for prog in $progs; do
    # Получение названия прграммы
    prog="${prog%%.c}"
    prog="${prog##../progs/}"
    # Создание каталогов для получения измерений при их отсутствии 
    if ! [ -d ../measures/"$prog" ]; then
        mkdir ../measures/"$prog"
    fi
    # Проход по оптимизациям
    for opt in $opts; do
        if ! [ -d ../measures/"$prog"/"$opt" ]; then
            mkdir ../measures/"$prog"/"$opt"
        fi
        # Проход по размерам массивов
        for len in "${!matrix_sizes[@]}";do
            i=0
            while [ "$i" -lt "$runs" ]; do
                ../apps/"$prog"_"$opt".exe "${matrix_sizes[len]}" >> ../measures/"$prog"/"$opt"/"${matrix_sizes[len]}".txt
            i=$((i+1))
            done
        done
        echo -e "\e[1;32mUpdated measures for ""$prog""_""$opt""\e[0m"
    done
done

echo -e "\e[1;32mMeasures successfully updated\e[0m"
