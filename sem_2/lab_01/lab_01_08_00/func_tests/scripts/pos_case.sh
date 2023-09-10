#!/bin/bash

#Проверка кол-ва переданных параметров
if [ $# -ne 2 ]; then
	exit 1
fi

in_test=$1 #Входные тестовые данные
out_test=$2 #Выходные тестовые данные

app=./app.exe
out_file="out.txt" #Файл сборки выходных данных программы
success=0 #Положительный код возврата
fail=1 #Негативный код возврата 

"$app" < "$in_test" > "$out_file"
exit_code=$? #Код возврата программы

#Проверка кода возврата
if [[ $exit_code != 0 ]]; then
	exit "$fail"
fi

#Проверка кода возрата comporator.sh
if bash func_tests/scripts/comparator.sh "$out_file" "$out_test"; then
	exit "$success"
else
	exit "$fail"
fi