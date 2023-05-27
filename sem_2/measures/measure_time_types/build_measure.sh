#!/bin/bash

gcc -c ./*.c -O3 -Wall -Werror -Wpedantic -Wextra -DN_RES=1000 -Wvla -Wfloat-equal -Wfloat-conversion
gcc ./*.o -o app.exe -lm

echo -e "App \e[1;32msuccessful\e[0m builded"
