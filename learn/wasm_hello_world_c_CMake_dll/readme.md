# Welcome to wasm_hello_world_c_makefile_Dynamic_Linking

Back to [home](../readme.md)

This is an example of wasm using C language, CMake and Dynamic Linking.


It needs [Emscripten SDK (emsdk)](../readme.md#Installing-the-C-Emscripten-SDK)

After emsdk is installed, in order to use it, activate PATH and other environment variables in the current terminal:

```bash
source ../../../emsdk/emsdk_env.sh
```

Create a file `hello.c`:

```makefile

IDIR =./include
CC=emcc
CFLAGS=-I$(IDIR)

ODIR=obj
LDIR =./lib


singlehello.js: hellomake.o hellofunc.o
	$(CC) $^ -o $@

hellomake.o: src/hellomake.c
	$(CC) -c $^ -o $@ $(CFLAGS)

hellofunc.o: src/hellofunc.c
	$(CC) -c $< -o $@ $(CFLAGS)

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~

```

To compile:

```bash
make

# or
emmake make
```
To run:

```bash
node singlehello.js
```

## Dynamic Linking

 In order to instruct the compiler to know if a file shall be compiled as a Dynamic Library or the Main Module, use the following options

 ```Makefile
-s SIDE_MODULE=1
-s MAIN_MODULE=1
 ```

E.g.:
 ```bash
emcc src/hellofunc.c -s SIDE_MODULE=1 -Iinclude -o hellofunc.wasm

emcc src/hellomake.c hellofunc.wasm -s MAIN_MODULE=1 -Iinclude -o hellomake.wasm

 ```

### Downsides of Using Dynamic Libraries

>**Note:** dynamic linking so far is not recommended because dynamic libraries have relocations for memory and function pointers, which add overhead.

