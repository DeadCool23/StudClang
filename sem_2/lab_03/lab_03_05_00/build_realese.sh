#!/bin/bash

gcc -c ./*.c -O3 -std=c99 -Wall -Werror -Wpedantic -Wextra -Wvla -Wfloat-equal -Wfloat-conversion
gcc ./*.o -o app.exe -lm
