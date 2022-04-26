#!/bin/bash

cd ../lib
make
cd ../l1

g++ -c main.cpp
g++ -o a.out main.o ../lib/MT.o ../lib/BM.o

output="output.txt"
./a.out > $output
python plot.py $output