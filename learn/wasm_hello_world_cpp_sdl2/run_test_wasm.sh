#!/bin/bash

rm *.wasm
rm *.js
rm *.html
rm *.o

echo "WASM Create Main file"
emcc src/example.cpp -o example.html -s USE_SDL=2

echo "WASM Open server"
emrun example.html

