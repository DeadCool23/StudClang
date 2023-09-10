#!/bin/bash

#Проверка кол-ва переданных параметров
if [ $# -ne 3 ]; then
	exit 1
fi

out_test=$2 #Выходные тестовые данные
IFS=' ' read -ra test_args <<< "$(cat "$3")"
#Команда запуска исполняемого файла
app="./app.exe"

out_file="out.txt" #Файл сборки выходных данных программы
success=0 #Положительный код возврата
fail=1 #Негативный код возврата
"$app" "${test_args[@]}" > "$out_file"
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
