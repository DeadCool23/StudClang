#!/bin/bash

clang -c main.c -O0 -g3 -fsanitize=memory -fPIE -fno-omit-frame-pointer -std=c99 -Wall -Werror -Wextra -Wpedantic
clang -o app.exe main.o -fsanitize=memory -lm