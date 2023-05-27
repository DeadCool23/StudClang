#!/bin/bash

graphs="$(ls ./graph_draw)"

for graph in $graphs; do
    gnuplot -persist ./graph_draw/"$graph"
done

echo -e "\e[1;32mGraph is created\e[0m"
