#!/bin/bash

./build_apps.sh
./update_data.sh 100
python3 make_preproc.py
echo -e "\e[1;32mData is calculate\e[0m"
./make_postproc.sh
