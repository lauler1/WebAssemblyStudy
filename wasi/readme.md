# GTK_web_wasm/learn

Back to [home](../README.md)

## Links

 - [wasi_js](wasi_js/readme.md)
 - [wasmtime](wasmtime/readme.md)
 - [wasi hello world](./wasi_hello_world/readme.md)


## WASI SDK and Clang/LLVM

Using the WASI SDK, you can compile C code into WebAssembly with WASI support.

You can download the latest version from the [WASI releases page](https://github.com/WebAssembly/wasi-sdk/releases). At the time of this writing, the latest version is ```14.0```. Here’s a command line example for a Mac:

```bash
$ curl -O -sSL https://github.com/WebAssembly/wasi-sdk/releases/download/wasi-sdk-14/wasi-sdk-14.0-macos.tar.gz
$ tar xf wasi-sdk-14.0-macos.tar.gz

```

Or compile from [Source Code](https://github.com/WebAssembly/wasi-sdk)

