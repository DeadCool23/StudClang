#!/bin/bash

here="./*.sh"
in_tests="./func_tests/scripts/*.sh"

for file in $here $in_tests; do
	shellcheck "$file" #Проверка скриптов
done
