# GTK_web_wasm/learn

Back to [home](../README.md)

## Links

 - [book: handsonGameDevelopmentwithWebAssembly](handsonGameDevelopmentwithWebAssembly/readme.md)
 - [book: the art of webassembly](theartofwebassembly/readme.md)
 - [wasi_js](wasi_js/readme.md)
 - [wasm hello world c](./wasm_hello_world_c/readme.md)
 - [wasm hello world c CMake dll](wasm_hello_world_c_CMake_dll/readme.md)
 - [wasm hello world c CMake dlopen](wasm_hello_world_c_CMake_dlopen/readme.md)
 - [wasm hello world c CMake static](wasm_hello_world_c_CMake_static/readme.md)
 - [wasm hello world c dlopen](wasm_hello_world_c_dlopen)
 - [wasm hello world c makefile](wasm_hello_world_c_makefile/readme.md)
 - [wasm hello world c makefile Dynamic Linking](wasm_hello_world_c_makefile_Dynamic_Linking/readme.md)
 - [wasm hello world c multiple sources](wasm_hello_world_c_multiple_sources/readme.md)
 - [wasm hello world c shell minimal](wasm_hello_world_c_shell_minimal/readme.md)
 - [wasmtime](wasmtime/readme.md)

## Installing the C Emscripten SDK (emsdk)

 - [Instructions](https://emscripten.org/docs/getting_started/downloads.html)

On Linux

```bash
# Get the emsdk repo
git clone https://github.com/emscripten-core/emsdk.git

# Enter that directory
cd emsdk

# Fetch the latest version of the emsdk (not needed the first time you clone)
git pull

# Download and install the latest SDK tools.
./emsdk install latest

# Make the "latest" SDK "active" for the current user. (writes .emscripten file)
./emsdk activate latest

# Activate PATH and other environment variables in the current terminal
source ./emsdk_env.sh
```

## Wasm wasm-objdump

To install:

```bash
sudo apt-get install wabt
```

## Running Code Space in Corporate with security restrictions# # 

Chromium command line (Windows)

```bash
ungoogled-chromium-portable.exe --disable-web-security --test-type
```

I also needed to add the `main.vscode-cdn.net`, `[*.]vscode-unpkg.net` and `vscodeweb.azureedge.net` to both `settings/Privacy and security/content/javascript/Allowed` to use `Javascript` and also to `settings/Privacy and security/content/Additional content settings/Insecure content`.

See [chrome Control use of insecure content exceptions configuration](https://support.google.com/chrome/a/answer/2657289?hl=en#zippy=%2Cpolicies-set-for-users%2Callow-insecure-content-on-these-sites%2Ccontrol-use-of-insecure-content-exceptions).


