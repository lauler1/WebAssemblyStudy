# Welcome to wasm_hello_world_c

Back to [home](../readme.md)

This is an example of wasm using C language and html template


It needs [Emscripten SDK (emsdk)](../readme.md#Installing-the-C-Emscripten-SDK)

After emsdk is installed, in order to use it, activate PATH and other environment variables in the current terminal:

```bash
source ../../../emsdk/emsdk_env.sh
```
Create a file `hello.c`:

```C
#include <stdio.h>

int main() {
    printf("Hello World\n");
    return 0;
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
