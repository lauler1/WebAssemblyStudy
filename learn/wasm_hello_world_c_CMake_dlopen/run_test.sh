#!/bin/bash

rm *.wasm
rm *.o

echo "Create Main file"
echo "  1 Target hellomake.o:"
emcc -fPIC -g ./src/hellomake.c -I./include -o hellomake.o -c
echo "  2 Target WasmHelloWorldCMake.js:"
emcc -s MAIN_MODULE=1 hellomake.o -o WasmHelloWorldCMake.js


echo "Create a Side file"
echo "  1 Target mylibfile.o:"
emcc -fPIC -g -I./include ./src/lib/hellofunc.c -o mylibfile.o -c

echo "  2 Target mylibfile.wasm:"
emcc -s SIDE_MODULE=1 mylibfile.o -o mylibfile.wasm


echo "Test if it runs"
node WasmHelloWorldCMake.js

echo "Create mylibfile2.wat"
wasm2wat mylibfile.wasm -o mylibfile2.wat

# Old commands

#emcc @src/lib/CMakeFiles/mylibfile.dir/includes_C.rsp -fPIC -s SIDE_MODULE=1 ../src/lib/hellofunc.c -s SIDE_MODULE=1 -o mylibfile.o
#emar rcs mylibfile.a mylibfile.o
#emcc -s SIDE_MODULE=1 mylibfile.a -o mylibfile.wasm
#emcc ./src/lib/hellofunc.c -s SIDE_MODULE=1 -I./include -o mylibfile.wasm


