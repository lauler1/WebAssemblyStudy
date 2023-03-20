#!/bin/bash

echo "BUILDING..."

../../../wasi-sdk/build/install/opt/wasi-sdk/bin/clang --target=wasm32-wasi --sysroot=../../../wasi-sdk/build/install/opt/wasi-sdk/share/wasi-sysroot/ hello.c -o hello.wasm


if [ $? -eq 0 ]; then
	echo "OK"
    wasmtime hello.wasm
else
    echo "FAIL"
fi
