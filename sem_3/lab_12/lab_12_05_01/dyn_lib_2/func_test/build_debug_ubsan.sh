#!/bin/bash

cd ..
make ubsan -s
cd func_test || exit 1

cp ./../app.exe .