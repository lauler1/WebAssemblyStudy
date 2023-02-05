#!/bin/bash

rm *.o
rm *.out

echo "NATIVE Create Main file"
clang src/example.cpp -o example.out -lSDL2


