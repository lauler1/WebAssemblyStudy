# Welcome to wasmtime

Back to [home](../readme.md)

This is an example in Rust of how to use wasmtime from the instalation page [instalation page)](https://wasmtime.dev/).

It needs Rust. Create a file `hello.rs`:

```rust
fn main() {
    println!("Hello, world!");
}
```

Create a file `hello.rs`:

```bash
$ rustup target add wasm32-wasi
$ rustc hello.rs --target wasm32-wasi
$ wasmtime hello.wasm
Hello, world!
```
