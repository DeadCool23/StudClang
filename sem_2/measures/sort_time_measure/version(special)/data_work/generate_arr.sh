#!/bin/bash

function reg
{
	echo "$1" | tr '[:upper:]' '[:lower:]'
}

function sorted_generate {
    i=1
    arr=""
    while [[ "$i" -le "$1" ]]; do
        if [ $i -eq "$1" ]; then
            arr+="$i"
        else
            arr+="$i, "
        fi
        i=$((i + 1))
    done
    echo "$1|$arr" >> "data/arrs/sorted"
}

function random_generate {
    i=1
    min=1
    max=100
    arr=""
    while [[ "$i" -le "$1" ]]; do
        if [ $i -eq "$1" ]; then
            arr+="$(shuf -i $min-$max -n 1)"
        else
            arr+="$(shuf -i $min-$max -n 1), "
        fi
        i=$((i + 1))
    done
    echo "$1|$arr" >> "data/arrs/random"
}

arr_type=$(reg "$1")
arr_len=$2


if [[ "$arr_type" == "s" ]]; then
    if [[ -z "$(! grep "$arr_len|" data/arrs/sorted)" ]]; then
        sorted_generate "$arr_len"
    fi
elif [[ "$arr_type" == "r" ]]; then
    if [[ -z "$(! grep "$arr_len|" data/arrs/random)" ]]; then
        random_generate "$arr_len"
    fi
fi
