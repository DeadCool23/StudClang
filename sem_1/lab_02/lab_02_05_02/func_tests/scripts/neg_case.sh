#!/bin/bash

#Проверка кол-ва переданных параметров
if [ $# -ne 1 ]; then
	exit 1
fi

in_test=$1 #Входные тестовые данные
app="./app.exe" #Команда запуска исполняемого файла

success=0 #Положительный код возврата
fail=1 #Негативный код возврата 

"$app" < "$in_test" > "out.txt"
exit_code=$? #Код возврата программы

if [[ $exit_code != 0 ]]; then
	exit "$success"
else
	exit "$fail"
fi
