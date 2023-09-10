#!/bin/bash

#Проверка кол-ва переданных параметров
if [ $# -ne 2 ]; then
	exit 1
fi

out_prog=$1 #Вывод программы
out_test=$2 #Предполагаем вывод программы

reg="Result: (.*)" #Маска чисел

filt_prog=$(grep -E -o "$reg" < "$out_prog") #Фильтрация выходных данных программы
filt_test=$(grep -E -o "$reg" < "$out_test") #Фильтрация тестовых данных

#Сравнение отфильрованных данных
if [ "$filt_prog" != "$filt_test" ]; then
	exit 1
fi

exit 0
