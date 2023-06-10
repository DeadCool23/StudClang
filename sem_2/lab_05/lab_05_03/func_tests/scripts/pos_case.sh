#!/bin/bash

#Проверка кол-ва переданных параметров
if [ $# -ne 4 ]; then
	exit 1
fi

in_test=$1 #Входные тестовые данные
out_test=$2 #Выходные тестовые данные
IFS=' ' read -ra test_args <<< "$(cat "$3")"
#Команда запуска исполняемого файла
app="./app.exe"

out_file="out.txt" #Файл сборки выходных данных программы
out_test_txt="outt.txt" #Файл для проверки изменненого бинарного файла
success=0 #Положительный код возврата
fail=1 #Негативный код возврата 

if [[ "$4" == "stdout" ]]; then
    "$app" "${test_args[@]}" < "$in_test" > "$out_file"
elif [[ "$4" == "f" ]]; then
    "$app" "${test_args[@]}" < "$in_test" > "$out_file" 
fi

exit_code=$? #Код возврата программы

#Проверка кода возврата
if [[ $exit_code != 0 ]]; then
	exit "$fail"
fi

if [[ "$4" == "f" ]]; then
    #Конвертация полученных бинарных файлов в текстовые
    ./conv.exe -b2t "$in_test" "$out_file"
    ./conv.exe -b2t "$out_test" "$out_test_txt"
    out_test="$out_test_txt"
fi

#Проверка кода возрата comporator.sh
if bash func_tests/scripts/comparator.sh "$out_file" "$out_test"; then
	exit "$success"
else
	exit "$fail"
fi
