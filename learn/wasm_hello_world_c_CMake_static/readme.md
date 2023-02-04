# Welcome to wasm_hello_world_c_CMake_static

Back to [home](../readme.md)

This is an example of wasm using C language, CMake and staticaly Linking.


It needs [Emscripten SDK (emsdk)](../readme.md#Installing-the-C-Emscripten-SDK)

After emsdk is installed, in order to use it, activate PATH and other environment variables in the current terminal:

```bash
source ../../../../emsdk/emsdk_env.sh
```

Considering that this example project is in a sub folder calles [PROJ_DIR], the CMake build folder will be ```[PROJ_DIR]/build```

To generate the Makefile Native(not Wasm):

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

```

The executable/output files will be in ```[PROJ_DIR]/bin ```

To run Native from ```[PROJ_DIR]/build```:

```bash
../bin/WasmHelloWorldCMake
```
To run WASM from ```[PROJ_DIR]/build```:

```bash
node ../bin/WasmHelloWorldCMake.js
```

