#!/bin/bash

#Проверка кол-ва переданных параметров
if [ $# -ne 1 ]; then
	exit 1
fi

IFS=' ' read -ra test_args <<< "$(cat "$1")"
#Команда запуска исполняемого файла
app="./app.exe"

success=0 #Положительный код возврата
fail=1 #Негативный код возврата 

err=$success

"$app" "${test_args[@]}"
exit_code=$? #Код возврата программы

#Проверка кода возврата
if [[ $exit_code == 0 ]]; then
	err=$fail
fi

report="report.txt"
valgrind --leak-check=full --quiet --log-file="$report" "$app" "${test_args[@]}"

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
