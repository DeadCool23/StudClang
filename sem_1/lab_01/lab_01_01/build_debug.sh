#!/bin/bash

gcc -c main.c -g -O0 -std=c99 -Wall -Werror -Wpedantic -Wextra -Wvla -Wfloat-equal -Wfloat-conversion
gcc main.o -o app.exe -lm