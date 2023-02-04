#include "hellomake.h"
#include <dlfcn.h>
#include <stdio.h>
#include <emscripten.h>

int main() {

    void *handle;
    typedef void (*func_t)(void);

    handle = dlopen("mylibfile.wasm", RTLD_NOW);

    if (!handle) {
        printf("failed to open the library\n");
        return 0;
    }
    func_t func = (func_t)dlsym(handle, "myPrintHelloMake");

    if (!func) {
        printf("failed to find the method\n");
        dlclose(handle);
        return 0;
    }
	// call a function in another file
	func();

	printf("End\n");
  
	//return(0);
}
