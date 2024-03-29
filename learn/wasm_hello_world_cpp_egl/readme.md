# Welcome to wasm_hello_world_cpp_egl

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

> **_NOTE:_**  Emscripten currently (2023) only provides SDL working in the browser, not WASI.

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

https://github.com/boostorg/boost

