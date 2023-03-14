'use strict';

const webgl = require('webgl-raub');

//const { createCanvas, loadImage } = require('canvas');
//const canvas = createCanvas(200, 200);
const { Document } = require('glfw-raub');




Document.setWebgl(webgl);
const document = new Document();
webgl.canvas = document;
const frame = document.requestAnimationFrame;

let gl;

const initContext = canvas => {
	try {
		gl = canvas.getContext('webgl');
		//gl = canvas.getContext('2d')
		
	} catch (e) {
		console.error('Could not initialise WebGL, sorry :-(');
		console.error(e);
		process.exit(-1);
	}
};



const drawScene = () => {
	gl.viewport(0, 0, gl.drawingBufferWidth, gl.drawingBufferHeight);
	gl.clear(gl.COLOR_BUFFER_BIT | gl.DEPTH_BUFFER_BIT);
};

const tick = timeNow => {
	drawScene();
	gl.finish(); // for timing
	frame(tick, 0);
};

const start = () => {
	const canvas = document.createElement('canvas');
	
	initContext(canvas);
	// Set clear color to black, fully opaque
	gl.clearColor(1.0, 0.0, 0.0, 1.0);
	// Clear the color buffer with specified clear color
	gl.clear(gl.COLOR_BUFFER_BIT);
	
	tick(Date.now());
};

start();

