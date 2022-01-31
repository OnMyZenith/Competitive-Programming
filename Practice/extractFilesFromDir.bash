#!/bin/bash

for dateFolder in */
do
    mv ./$dateFolder/* ./
    rm -rf ./$dateFolder
done