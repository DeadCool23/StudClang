#!/bin/bash

cd ..
make msan -s
cd func_test || exit 1

cp ./../app.exe .