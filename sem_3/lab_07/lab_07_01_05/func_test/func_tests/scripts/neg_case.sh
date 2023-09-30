#!/bin/bash

#Проверка кол-ва переданных параметров
if [ $# -ne 1 ]; then
	exit 1
fi

IFS=' ' read -ra test_args <<< "$(cat "$1")"
#Команда запуска исполняемого файла
app="./../app.exe"

success=0 #Положительный код возврата
fail=1 #Негативный код возврата 

err=$success

"$app" "${test_args[@]}"
exit_code=$? #Код возврата программы

#Проверка кода возврата
if [[ $exit_code != 0 ]]; then
	err=$fail
fi

valgrind --leak-check=yes --leak-resolution=med --quiet --log-file="report.txt" "$app" "${test_args[@]}"

if [[ -n $report ]] && [[ $err -eq $fail ]]; then
	exit 1
elif [[ -n $report ]] && [[ $err -eq $success ]]; then
	exit 2
elif [[ -f $report ]] && [[ $err -eq $fail ]]; then
	exit 3
else
	exit 0
fi

