#!/bin/bash

reg='.(sh|c|h|py)$' #Маска немусорных файлов
files=$(ls)
for file in $files; do
	#Проверка на мусорный файл
	if [[ -f "$file" && ! "$file" =~ $reg ]]; then
		rm -f "$file" #Удаление файла
	fi
done

rm -fr libs

cd ..
make clean -s