#!/bin/bash

rm *.wasm
rm *.o

emcc ./src/lib/hellofunc.c -s SIDE_MODULE=1 -I./include -o mylibfile.wasm

emcc ./src/hellomake.c -s MAIN_MODULE=1 -I./include -o WasmHelloWorldCMake.js

node WasmHelloWorldCMake.js

#emcc -s SIDE_MODULE=1 mylibfile.a -o mylibfile.wasm

