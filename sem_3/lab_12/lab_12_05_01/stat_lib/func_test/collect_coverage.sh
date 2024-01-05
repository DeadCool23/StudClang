#!/bin/bash

bash build_coverage.sh

ful_cov="Lines executed:[0-9]*(\.[0-9]+)?%"
percent="[0-9]*(\.[0-9]+)?" #Регулярное выражение для поиска числа с плавающей точкой
key=$1 #Ключ -v
min_per=70

#Вызов func_tests.sh
if [[ "$key" == "-v" ]]; then
    bash func_tests/scripts/func_tests.sh -v
else
    bash func_tests/scripts/func_tests.sh
fi

exit_code=$? #Код возврата func_tests.sh

cd ../src || exit 1
c_files=$(ls ./*.c)
cd ../out || exit 1

gcov $c_files > out.txt 2> /dev/null #Направление работы gcov в out.txt
proj_cov=$(grep -E -o "$ful_cov" < "out.txt") #Получение процента покрытия
cov=()
readarray -t cov < <(grep -E -o "$percent" <<< "$proj_cov")
ful_cov=${cov[${#cov[@]}-1]}
int_cov=${ful_cov%%.*}

#Вывод при наличии ключа
if [[ "$key" == "-v" ]]; then
    if [[ $int_cov -ge $min_per ]]; then
        echo -e "\e[1;32mCoverage ration $ful_cov%\e[0m"
    else
        echo -e "\e[1;31mCoverage ration $ful_cov%\e[0m"
    fi
    echo "========================================"
fi

cd ../func_test || exit 1

#Определяем код возврата
if [[ $int_cov -ge $min_per ]] && [[ "$exit_code" == "0" ]]; then
    exit 0
else
    exit 1
fi
