#!/bin/bash

gcc -c main.c -O3 -std=c99 -Wall -Werror -Wpedantic -Wextra -Wvla -Wfloat-equal -Wfloat-conversion
gcc main.o -o app.exe -lm