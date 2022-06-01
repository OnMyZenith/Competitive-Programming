#!/bin/bash
comp="g++ -std=c++17 -Wall -Wextra -pedantic -O2 -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align"

echo -n "Compiling $1.cpp..."
$comp $1.cpp -o $1
echo "done!"
echo -n "Compiling $1_brute.cpp..."
$comp $1_brute.cpp -o $1_brute
echo "done!"
echo -n "Compiling $1_gen.cpp..."
$comp $1_gen.cpp -o $1_gen
echo "done!"

echo "Starting Stress Test..."
echo
for((i = 1; ; ++i)); do
    ./$1_gen $i > $1_int
    ./$1 < $1_int > $1_out
    ./$1_brute < $1_int > $1_out_brute
    echo "-------------------$i--------------------"
    # echo "Input:"
    # cat $1_int
    # echo
    # echo "$1 Output:"
    # cat $1_out
    # echo
    # echo "$1_brute Output:"
    # cat $1_out_brute
    # echo
    diff -w $1_out $1_out_brute || break
done