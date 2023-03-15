#!/bin/bash

rm *.wasm
rm *.js
rm *.html
rm *.o

echo "WASM Create Main file"
emcc src/example.c  src/esUtil.c -I./include -o example.html

echo "WASM Open server"
emrun example.html

