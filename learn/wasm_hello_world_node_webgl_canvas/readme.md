# Welcome to wasm_hello_world_node_webgl_canvas

Back to [home](../readme.md)

This is another example of how to use the node canvas to access webgl using a different node library called webgl-raub. This is a study, it does not use wasm (yet), but this can be a way to understand how to create GUI with wasm using Nodejs outside the Browser.
It can open a native window to present the webgl graphics and also uses a canvas that may allow the same code be used by wasm in web and in node.


It needs [webgl-raub](https://github.com/node-3d/webgl-raub).
This is part of project [Node3D](https://github.com/node-3d).

To build and test it, use:
```bash
npm init

npm i

#To run:
node main.js

```

# Other option to be explored

To explore opening window in nodejs, I tried and worked:

 - [NPM node-x11](https://www.npmjs.com/package/x11)
   - [GIT node-x11](https://www.npmjs.com/package/x11)







