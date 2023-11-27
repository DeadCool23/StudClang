#!/bin/bash

# mem+;func+ - 0
# mem-;func- - 1
# mem-;func+ - 2
# mem+;func- - 3

#Проверка кол-ва переданных параметров
if [ $# -ne 3 ]; then
	exit 1
fi

out_test=$2 #Выходные тестовые данные
IFS=' ' read -ra test_args <<< "$(cat "$3")"
#Команда запуска исполняемого файла
app="./../app.exe"

out_file="out.txt" #Файл сборки выходных данных программы
success=0 #Положительный код возврата
fail=1 #Негативный код возврата 

err=0

"$app" "${test_args[@]}" > "$out_file"
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

report="report.txt"
valgrind --leak-check=full --quiet --log-file="$report" "$app" "${test_args[@]}" > "$out_file"

dwarf_messages=$(grep "unhandled dwarf2 abbrev form code" "$report")

if [ -n "$dwarf_messages" ]; then
    rm -f "$report"
fi

if [[ -s $report ]]; then
    if [[ $err -eq $success ]]; then
        exit 2
    else
        exit 1
    fi
else
    if [[ $err -eq $success ]]; then
        exit 0
    else
        exit 3
    fi
fi
