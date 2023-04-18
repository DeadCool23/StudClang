#!/bin/bash

exit_count=0 #Кол-во кодов возврата
exit_scs=0 #Кол-во положительный кодов возврата
directs="lab_*" #Директории заданий лабораторной работы
for direct in $directs; do
	#Вывод при наличии ключа
	if [[ "$1" == "-v" ]]; then 
		echo -e "\e[1;33m$direct\e[0m"
		cd ./"$direct" || exit 1
		bash testing.sh -v #Запуск testing.sh в многословном режиме
		exit_code=$? #Код возврата testing.sh
		cd ..
	else
		cd ./"$direct" || exit 1
		bash testing.sh #Запуск collect_coverage.sh в молчаливом режиме
		exit_code=$? #Код возврата testing.sh
		cd ..
	fi
	
	exit_count=$((exit_count + 1)) #Счет кодов возврата
	if [ $exit_code -eq 0 ]; then
		exit_scs=$((exit_scs + 1)) #Счет положительных кодов возврата
	fi
done

#Определяем код возврата
if [ $exit_count -eq $exit_scs ]; then
	#Вывод при наличии ключа
	if [[ "$1" == "-v" ]]; then
		echo -e "\e[1;32mJob successfully completed!\e[0m"
	fi
	exit 0
else
	#Вывод при наличии ключа
	if [[ "$1" == "-v" ]]; then
		echo -e "\e[1;31mERROR: Job failed\e[0m"
	fi
	exit 1
fi