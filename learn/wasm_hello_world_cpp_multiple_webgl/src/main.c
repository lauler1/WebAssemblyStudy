#include <emscripten/html5.h>
#include <GLES2/gl2.h>
#include <GLFW/glfw3.h>
#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#endif

EMSCRIPTEN_WEBGL_CONTEXT_HANDLE ctx1;
EMSCRIPTEN_WEBGL_CONTEXT_HANDLE ctx2;

void handle_events() {
	emscripten_webgl_make_context_current(ctx1);
  	glClear(GL_COLOR_BUFFER_BIT);
	emscripten_webgl_make_context_current(ctx2);
  	glClear(GL_COLOR_BUFFER_BIT);
    //return 1;
}

int main(){
	
	EmscriptenWebGLContextAttributes attr;
	emscripten_webgl_init_context_attributes(&attr);

	ctx1 = emscripten_webgl_create_context("#canvas1", &attr);
	ctx2 = emscripten_webgl_create_context("#canvas2", &attr);

	emscripten_webgl_make_context_current(ctx1);
	glClearColor(100.0, 155.0, 0.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);

	emscripten_webgl_make_context_current(ctx2);
	glClearColor(100.0, 0.0, 100.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);


#ifdef __EMSCRIPTEN__
  emscripten_set_main_loop(handle_events, 0, 1);
#else
  while (handle_events())
    ;
#endif/*
	//emscripten_request_animation_frame_loop(handle_events, 0);

  while (1) {
	emscripten_webgl_make_context_current(ctx1);
  	glClear(GL_COLOR_BUFFER_BIT);
	//emscripten_webgl_make_context_current(ctx2);
  	//glClear(GL_COLOR_BUFFER_BIT);
#ifdef __EMSCRIPTEN__
    emscripten_sleep(1);
#endif
	}*/

	return 1;
}