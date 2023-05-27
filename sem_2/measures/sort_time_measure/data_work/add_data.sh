#!/bin/bash

function reg
{
	echo "$1" | tr '[:upper:]' '[:lower:]'
}

echo -e "\033[1;35mScript add data in dataset\033[0m"
echo ""

echo "What data should be updated?"

echo -n "[R]eset to default [A]rrays [N]othing: "
read -r command
command=$(reg "$command")
if [[ "$command" == "a" ]]; then
    echo -e "\e[1;32mAdding arrays in data\e[0m"
    repeat="y"
    is_added=0
    while [[ "$repeat" == y ]] && [[ "$command" != "n" ]]; do
        echo -e "\e[1;37mChoose array type\e[0m"
        echo -n "[S]orted [R]andom: "
        read -r arr_type
        if [[ "$arr_type" == "s" ]] || [[ "$arr_type" == "r" ]]; then
            echo -n "Input size of added array: "
            read -r arr_size
            echo ""
            if [[ "$arr_size" =~ ( +)?^[0-9]+( +)?$ ]]; then
                ./generate_arr.sh "$arr_type" "$arr_size"
                is_added=1
                echo "Add another one?"
                echo -n "[Y]es [N]o (default No): "
                read -r repeat
                repeat="$(reg "$repeat")" 
                if [[ "$repeat" != "y" ]]; then
                    command="n"
                fi
            else
                command="n"
            fi
        else
            command="n"
        fi
    done
    if [ $is_added -eq 1 ]; then
        echo -e "Array(s) \e[1;32msuccessfully\e[0m added"
    fi
elif [[ "$command" == "r" ]]; then
    echo -e "\e[1;32mReset data to default config\e[0m"
    if [[ -f "data/arrs/inverse_sorted" ]]; then
        rm data/arrs/inverse_sorted
    fi
    cp def_data/def_arrs/def_sorted data/arrs/sorted
    cp def_data/def_arrs/def_random data/arrs/random
else
    command="n"
fi
if [[ "$command" == "n" ]]; then
    echo "Script stop working...."
fi
