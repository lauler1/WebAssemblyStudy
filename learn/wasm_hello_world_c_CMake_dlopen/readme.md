# Welcome to wasm_hello_world_c_CMake_dlopen

Back to [home](../readme.md)

This is an example of wasm using C language, CMake and Dynamic Linking which is dynamically loaded using dlopen.
It is based on [Welcome to wasm_hello_world_c_CMake_dll](../Welcome to wasm_hello_world_c_CMake_dll)


It needs [Emscripten SDK (emsdk)](../readme.md#Installing-the-C-Emscripten-SDK)

After emsdk is installed, in order to use it, activate PATH and other environment variables in the current terminal:

```bash
source ../../../../emsdk/emsdk_env.sh
```

Considering that this example project is in a sub folder calles [PROJ_DIR], the CMake build folder will be ```[PROJ_DIR]/build```

To generate the Makefile Native(not Wasm, but Linux):

```bash

cd build
cmake ..

#or cmake .. --fresh
```

To generate the Makefile Wasm:

```bash

cd build
emcmake cmake ..

#or emcmake cmake .. --fresh

```

The ```--fresh``` option is new for CMake 3.24, [see.](https://stackoverflow.com/questions/9680420/looking-for-a-cmake-clean-command-to-clear-up-cmake-output) It creats the project deleting all previous build files.

To compile (both: Native and WASM):

```bash
make
make install

#or make clean all install 
```

The executable/output files will be in ```[PROJ_DIR]/bin ```

To run Native from ```[PROJ_DIR]/build```:

```bash
export LD_LIBRARY_PATH=${LD_LIBRARY_PATH}:${PWD}/../bin
../bin/WasmHelloWorldCMake
```

The ```export LD_LIBRARY_PATH``` is necessary at the first time because Bash won't look for the .so file locally.

To run WASM from ```[PROJ_DIR]/build```:

```bash
node ../bin/WasmHelloWorldCMake.js
```

## CMAKE

I use 2 separate projects here, one for the main app and another for the Lib.
The main project is defined in the CMakeLists in the root folder.
The lib project is managed in the ```src/lib``` folder

## Dynamic Linking

 In order to instruct the compiler to know if a file shall be compiled as a Dynamic Library or the Main Module, use the following options

 ```Makefile
-s SIDE_MODULE=1
-s MAIN_MODULE=1
 ```

Manual building and testing can be seen in the files ```run_dload.sh``` and ```run_test.sh```. The ```run_dload.sh``` is the simplest way, but it is not the way that CMake does. CMakes always separate the building in 2 steps, compiling and linking. The ```run_test.sh``` buils in 2 steps.

### Downsides of Using Dynamic Libraries

>**Note:** dynamic linking so far is not recommended because dynamic libraries have relocations for memory and function pointers, which add overhead.

