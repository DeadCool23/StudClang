#!/bin/bash


#Компиляция программы с проверкой покрытия кода
cd ..
make coverage -s
cd func_test || exit 1

cp ./../app.exe .