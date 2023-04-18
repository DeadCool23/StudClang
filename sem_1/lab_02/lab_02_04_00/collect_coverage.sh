#!/bin/bash

bash build_coverage.sh

percent="[0-9]+\.?[0-9]+%" #Регулярное выражение для поиска процента
key=$1 #Ключ -v

#Вызов func_tests.sh
if [[ "$key" == "-v" ]]; then
    bash func_tests/scripts/func_tests.sh -v
else
    bash func_tests/scripts/func_tests.sh
fi

exit_code=$? #Код возврата func_tests.sh

gcov main.c > out.txt #Направление работы gcov в out.txt
cov=$(grep -E -o -m 1 "$percent" < "out.txt") #Получение процента покрытия

#Вывод при наличии ключа
if [[ "$key" == "-v" ]]; then
    if [[ "$cov" == "100.00%" ]]; then
        echo -e "\e[1;32mCoverage ration $cov\e[0m"
    else
        echo -e "\e[1;31mCoverage ration $cov\e[0m"
    fi
    echo "========================================"
fi

#Определяем код возврата
if [[ "$cov" == "100.00%" && "$exit_code" == "0" ]]; then
    exit 0
else
    exit 1
fi
