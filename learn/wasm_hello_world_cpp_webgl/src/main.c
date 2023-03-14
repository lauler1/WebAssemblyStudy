#include <emscripten/html5.h>
#include <GLES2/gl2.h>
//#ifdef __EMSCRIPTEN__
//#include <emscripten.h>
//#endif
int handle_events() {
  	glClear(GL_COLOR_BUFFER_BIT);
    return 1;
}

int main(){
	EmscriptenWebGLContextAttributes attr;
	emscripten_webgl_init_context_attributes(&attr);

	EMSCRIPTEN_WEBGL_CONTEXT_HANDLE ctx = emscripten_webgl_create_context("#canvas", &attr);
	emscripten_webgl_make_context_current(ctx);

	glClearColor(100.0, 155.0, 0.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);

	emscripten_request_animation_frame_loop(handle_events, 0);
	//while(1){glClear(GL_COLOR_BUFFER_BIT);};

	return 1;
}