# Welcome to wasm_hello_world_c_multiple_sources

Back to [home](../readme.md)

This is an example of wasm using C language with more than 1 function in the file


It needs [Emscripten SDK (emsdk)](../readme.md#Installing-the-C-Emscripten-SDK)

After emsdk is installed, in order to use it, activate PATH and other environment variables in the current terminal:

```bash
source ../../../emsdk/emsdk_env.sh
```

Create a file `hello3.c`:


```C
#include <stdio.h>
#include <emscripten/emscripten.h>

int main() {
    printf("Hello World\n");
    return 0;
}

#ifdef __cplusplus
#define EXTERN extern "C"
#else
#define EXTERN
#endif

EXTERN EMSCRIPTEN_KEEPALIVE void myFunction(int argc, char ** argv) {
    printf("MyFunction Called\n");
}

```

To compile:

```bash
emcc hello.c -o hello.js
```
To run:

```bash
node hello.js
```
or compile to run in a HTML

```bash
emcc hello.c -o hello.html
```

This option will need a server to run or run the Browser disabling the security rules.

