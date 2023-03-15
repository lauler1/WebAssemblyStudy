# Welcome to wasm_hello_world_cpp_svgpp

Back to [home](../readme.md)

This is an example of wasm using C language and SDL to render images and events. It is based on [drawing-to-canvas-in-emscripten](https://web.dev/drawing-to-canvas-in-emscripten/).


It needs [Emscripten SDK (emsdk)](../readme.md#Installing-the-C-Emscripten-SDK).

To build and test it in WASM, use:
```bash
emcc example.cpp -o example.html -s USE_SDL=2

# or run_test_wasm.sh
```

To build and test it natively, use:

```bash
clang example.cpp -o example -lSDL2

# or run_test_native.sh
```

## WASM

To test the example, it is necessary to run a server and open it in a browser, e.g.:
```bash
emrun example.html
```


## Native

It may be needed to install SDL dev packet.

```bash
sudo apt install libsdl2-dev
```

Other packets can be good for further development, e.g.:

```bash
sudo apt install libsdl2-image-dev

sudo apt install libsdl2-mixer-dev

sudo apt install libsdl2-ttf-dev
```

See [how to install sdl on linux](https://learncgames.com/tutorials/how-to-install-sdl-on-linux/).

## Extra

http://kth.diva-portal.org/smash/get/diva2:1664916/FULLTEXT01.pdf


For SVG rendering, take a look:
https://github.com/svgpp/svgpp
https://github.com/kiba/SDL_svg


## Building Boos for WASM

[SVGPP](https://github.com/svgpp/svgpp) needs [Boost](https://github.com/boostorg/boost)


https://stackoverflow.com/questions/15724357/using-boost-with-emscripten


Install emsdk if you haven't already from https://emscripten.org/docs/getting_started/downloads.html

Navigate to the emsdk install folder and do

```bash
./emsdk install latest && ./emsdk activate latest && source ./emsdk_env.sh
```

Navigate to the directory where you want to clone the Boost repo and run

```bash
git clone --recursive https://github.com/boostorg/boost.git
```

You can add the argument '--jobs N' where N is the number of processes to clone submodules with (this will go a lot faster if you do this).

```bash
cd boost
```

Now use the bootstrap script to create the boost-build executable b2

```bash
./bootstrap.sh
```

Finally, as your emsdk is already activated from the step above, you can build Boost using emconfigure to configure everything as it needs to be for calls to gcc to use emscripten instead

```bash
emconfigure ./b2 toolset=gcc --prefix=<directory_to_install_to> --build-dir=<directory_for_intermediate_build_files>
```

Now to install the includes and libs to your chosen prefix directory, run

```bash
emconfigure ./b2 toolset=gcc --prefix=<directory_to_install_to> --build-dir=<directory_for_intermediate_build_files> install
```


