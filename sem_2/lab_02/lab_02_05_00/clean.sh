#!/bin/bash

reg='.(sh|c)$' #Маска немусорных файлов
files=$(ls)
for file in $files; do
	#Проверка на мусорный файл
	if [[ -f "$file" && ! "$file" =~ $reg ]]; then
		rm -f "$file" #Удаление файла
	fi
done
