'use strict';

const webgl = require('webgl-raub');
const { Document } = require('glfw-raub');

Document.setWebgl(webgl);

const document1 = new Document();
document1.makeCurrent();
const frame1 = document1.requestAnimationFrame;

const mycanvas1 = document1.createElement('canvas');
console.log("mycanvas1=",mycanvas1);
const myctx1 = mycanvas1.getContext('webgl');
console.log("myctx1=",myctx1);


const document2 = new Document();
document2.makeCurrent();
const frame2 = document2.requestAnimationFrame;

const mycanvas2 = document2.createElement('canvas');
console.log("mycanvas2=",mycanvas2);
const myctx2 = mycanvas2.getContext('webgl');
console.log("myctx2=",myctx2);

//var GL;
var color8b = 1.0;

const drawScene = () => {
	//GL.makeContextCurrent(myctx1);
};

const tick = timeNow => {
	color8b += 0.01;
	if(color8b > 1.0) color8b = 0.0;
	
	//webgl.WebGLRenderingContext(myctx1);
	document1.makeCurrent();
	myctx1.clearColor(color8b, 0.0, 0.0, 1.0);
	myctx1.viewport(0, 0, myctx1.drawingBufferWidth, myctx1.drawingBufferHeight);
	myctx1.clear(myctx1.COLOR_BUFFER_BIT | myctx1.DEPTH_BUFFER_BIT);
	myctx1.finish(); // for timing
	frame1(tick, 0);
	document2.makeCurrent();
	myctx2.clearColor(0.0, color8b, 0.0, 1.0);
	myctx2.viewport(0, 0, myctx2.drawingBufferWidth, myctx2.drawingBufferHeight);
	myctx2.clear(myctx2.COLOR_BUFFER_BIT | myctx2.DEPTH_BUFFER_BIT);
	myctx2.finish(); // for timing
	frame2(tick, 0);
};

const start = () => {
	//GL.makeContextCurrent(myctx1);
	
	document1.makeCurrent();
	// Set clear color to black, fully opaque
	myctx1.clearColor(color8b, 0.0, 0.0, 1.0);
	// Clear the color buffer with specified clear color
	myctx1.clear(myctx1.COLOR_BUFFER_BIT);
	
	document2.makeCurrent();
	// Set clear color to black, fully opaque
	myctx2.clearColor(0.0, color8b, 0.0, 1.0);
	// Clear the color buffer with specified clear color
	myctx2.clear(myctx2.COLOR_BUFFER_BIT);
	
	tick(Date.now());
};

start();
