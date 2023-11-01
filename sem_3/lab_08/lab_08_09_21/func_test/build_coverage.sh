#!/bin/bash


#Компиляция программы с проверкой покрытия кода
gcc -c ./../src/*.c --coverage -std=c99 -Wall -Werror -Wpedantic -Wextra -Wvla -Wfloat-equal -Wfloat-conversion -I ../inc
gcc ./*.o -o ./../app.exe -lm --coverage -I ../inc
