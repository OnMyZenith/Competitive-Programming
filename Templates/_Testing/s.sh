#!/bin/bash
comp="g++ -std=c++17 -Wall -Wextra -pedantic -O2 -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align"

$comp $1.cpp
$comp $1brute.cpp
$comp $1gen.cpp

for((i = 1; ; ++i)); do
    echo $i
    ./$1gen $i > $1int
    # ./a < int > out1
    # ./brute < int > out2
    # diff -w out1 out2 || break
    diff -w <(./$1 < $1int) <(./$1brute < $1int) || break
done