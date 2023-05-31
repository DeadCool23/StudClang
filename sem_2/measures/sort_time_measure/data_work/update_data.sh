#!/bin/bash

# Проверка введенного аргумента
if [[ "$1" =~ ^[0-9]+$ ]]; then
    runs=$1
else
    runs=10
fi

# Подсчет кол-ва замеров
was_runed="$(cat ../measures/runs.txt)"
is_runed=$((was_runed+runs))
echo "$is_runed" > ../measures/runs.txt 

progs="../progs/*.c"
opts=$(cat data/optimizations)
arr_types=$(ls data/arrs)

# Проход по прграммам
for prog in $progs; do
    # Получение названия прграммы
    prog="${prog%%.c}"
    prog="${prog##../progs/}"
    # Создание каталогов для получения измерений при их отсутствии 
    if ! [ -d ../measures/"$prog" ]; then
        mkdir ../measures/"$prog"
    fi
    # Проход по типам массивов
    for arr_type in $arr_types; do
        # Создание каталогов для получения измерений при их отсутствии 
        if ! [ -d ../measures/"$prog"/"$arr_type" ]; then
            mkdir ../measures/"$prog"/"$arr_type"
        fi
        readarray -t arrs <<< "$(cat data/arrs/"$arr_type")" # Получение размеров массивов
        # Проход по оптимизациям
        for opt in $opts; do
            # Создание каталогов для получения измерений при их отсутствии 
            if ! [ -d ../measures/"$prog"/"$arr_type"/"$opt" ]; then
                mkdir ../measures/"$prog"/"$arr_type"/"$opt"
            fi
            # Проход по размерам массивов
            for num in "${!arrs[@]}";do
                i=0
                while [ "$i" -lt "$runs" ]; do
                    ../apps/"$prog"_"$opt"_"$arr_type".exe "${arrs[num]}" >> ../measures/"$prog"/"$arr_type"/"$opt"/"${arrs[num]}".txt # Запись поченных изсерений в базу данных
                    i=$((i+1))
                done
            done
            echo -e "\e[1;32mUpdated measures for ""$prog""_""$opt""_""$arr_type""\e[0m"
        done
    done
done

echo -e "\e[1;32mMeasures successfully updated\e[0m"
