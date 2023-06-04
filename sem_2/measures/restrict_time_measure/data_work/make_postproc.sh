#!/bin/bash

graphs="$(ls ./graph_draw)" # Послучение скриптов для отрисовки графиков

for graph in $graphs; do
    gnuplot -persist ./graph_draw/"$graph" # Отрисовка графиков
done

echo -e "\e[1;32mGraph is created\e[0m"

