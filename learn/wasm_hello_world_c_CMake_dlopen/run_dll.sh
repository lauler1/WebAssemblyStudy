#!/bin/bash

cd ../wasm_hello_world_c_CMake_dll/build

echo "curr dir = ${PWD}"

emcmake cmake .. --fresh

make clean all install VERBOSE=1 > log.txt

node ../bin/WasmHelloWorldCMake.js

#emcc -s SIDE_MODULE=1 mylibfile.a -o mylibfile.wasm

