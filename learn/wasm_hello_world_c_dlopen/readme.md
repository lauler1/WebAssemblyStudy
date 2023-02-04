# Welcome to wasm_hello_world_c_dlopen

Back to [home](../readme.md)

This is an example of wasm using C language and Dynamic Linking which is dynamically loaded using dlopen.

It needs [Emscripten SDK (emsdk)](../readme.md#Installing-the-C-Emscripten-SDK)

After emsdk is installed, in order to use it, activate PATH and other environment variables in the current terminal:

```bash
source ../../../../emsdk/emsdk_env.sh
```

## Dynamic Linking

 In order to instruct the compiler to know if a file shall be compiled as a Dynamic Library or the Main Module, use the following options

 ```Makefile
-s SIDE_MODULE=1
-s MAIN_MODULE=1
 ```

E.g.:
 ```bash

emcc ./src/lib/hellofunc.c -s SIDE_MODULE=1 -I./include -o mylibfile.wasm
emcc ./src/hellomake.c -s MAIN_MODULE=1 -I./include -o WasmHelloWorldCMake.js

#Test
node WasmHelloWorldCMake.js
 ```

### Downsides of Using Dynamic Libraries

>**Note:** dynamic linking so far is not recommended because dynamic libraries have relocations for memory and function pointers, which add overhead.

