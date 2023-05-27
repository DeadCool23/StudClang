#!/bin/bash

n=500
echo -n "" > data/arrs/sorted
echo -n "" > data/arrs/random

while [ "$n" -le 10000 ]; do
    echo "$n" >> data/arrs/sorted
    echo "$n" >> data/arrs/random
    n=$((n+500))
done
