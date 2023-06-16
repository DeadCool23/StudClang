#!/bin/bash

function reg
{
	echo "$1" | tr '[:upper:]' '[:lower:]'
}

echo -e "\033[1;35mScript builds time measure program\033[0m"

echo -n "How many measurements program should do? (default 10): "
read -r meas_count
if [[ ! $meas_count =~ ^[0-9]+$ ]]; then
    meas_count=10
fi

sed -i "s/#define N_RES 10/#define N_RES $meas_count/" calc_measures_res.h

gcc -c ./*.c -O3 -Wall -Werror -Wpedantic -Wextra -Wvla -Wfloat-equal -Wfloat-conversion
gcc ./*.o -o app.exe -lm

sed -i "s/#define N_RES $meas_count/#define N_RES 10/" calc_measures_res.h

echo -e "App \e[1;32msuccessful\e[0m builded"
