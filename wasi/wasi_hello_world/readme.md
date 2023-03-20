# Welcome to wasi_hello_world

Back to [home](../readme.md)

To build and test it, use:

```bash
../../../wasi-sdk/build/install/opt/wasi-sdk/bin/clang --sysroot ../../../wasi-sdk/build/install/opt/wasi-sdk/share/wasi-sysroot/ hello.c -o hello.wasm

../../../wasi-sdk/build/install/opt/wasi-sdk/bin/clang --target=wasm32-wasi --sysroot=../../../wasi-sdk/build/install/opt/wasi-sdk/share/wasi-sysroot/ hello.c -o hello.wasm
```

