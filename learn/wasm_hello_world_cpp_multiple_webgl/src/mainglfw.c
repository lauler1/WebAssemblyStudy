//#include <emscripten/html5.h>
#include <GLES2/gl2.h>
#include <GLFW/glfw3.h>
#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#endif

GLFWwindow *window1, *window2;

int handle_events() {

  	glClear(GL_COLOR_BUFFER_BIT);

    return 1;
}

int main(){
	
    if (!glfwInit()) return 1;

    window1 = glfwCreateWindow(300, 200, "Input test1", NULL, NULL);
    //window2 = glfwCreateWindow(720, 720, "Input test2", NULL, NULL); //<-- This is not possible currently
	
	glfwMakeContextCurrent(window1);

	glClearColor(100.0, 155.0, 0.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);

	return 1;
}