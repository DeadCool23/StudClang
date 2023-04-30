#!/bin/bash

for c_file in *.c; do
	~/apps/CodeChecker/CodeChecker/CodeChecker.exe --rules ~/apps/CodeChecker/CodeChecker/Rules.txt "$c_file"
done
