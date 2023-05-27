#!/bin/bash

./build_apps.sh
./clean_data.sh
./update_data.sh 2000
python3 make_preproc.py
echo -e "\e[1;32mData is calculate\e[0m"
./make_postproc.sh
