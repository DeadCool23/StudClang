#!/bin/bash

cd ..
make asan -s
cd func_test || exit 1

cp ./../app.exe .
cp -r ../libs .