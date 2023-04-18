#!/bin/bash

#Компиляция программы с проверкой покрытия кода
gcc -c main.c --coverage -std=c99 -Wall -Werror -Wpedantic -Wextra -Wvla -Wfloat-equal -Wfloat-conversion
gcc main.o -o app.exe -lm --coverage