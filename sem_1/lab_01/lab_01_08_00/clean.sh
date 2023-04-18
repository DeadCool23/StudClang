#!/bin/bash

reg='.(sh|c)$' #Маска немусорных файлов
files=$(ls)
rm func_tests/scripts/*.txt 2> /dev/null #Удаление времменных файлов в func_tests/script
for file in $files; do
	#Проверка на мусорный файл
	if [[ -f "$file" && ! "$file" =~ $reg ]]; then
		rm -f "$file" #Удаление файла
	fi
done
