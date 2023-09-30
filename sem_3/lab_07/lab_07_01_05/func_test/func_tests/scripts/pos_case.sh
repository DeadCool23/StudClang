#!/bin/bash

# mem+;func+ - 0
# mem-;func- - 1
# mem-;func+ - 2
# mem+;func- - 3

#Проверка кол-ва переданных параметров
if [ $# -ne 2 ]; then
	exit 1
fi

out_test=$1 #Выходные тестовые данные
IFS=' ' read -ra test_args <<< "$(cat "$2")"
#Команда запуска исполняемого файла
app="./../app.exe"

out_file="func_tests/data/test_out.txt" #Файл сборки выходных данных программы
success=0 #Положительный код возврата
fail=1 #Негативный код возврата 

err=0

"$app" "${test_args[@]}"
exit_code=$? #Код возврата программы

#Проверка кода возврата
if [[ $exit_code != 0 ]]; then
	err=$fail
else
	#Проверка кода возрата comporator.sh
	if bash func_tests/scripts/comparator.sh "$out_file" "$out_test"; then
		err=$success
	else
		err=$fail
	fi
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

