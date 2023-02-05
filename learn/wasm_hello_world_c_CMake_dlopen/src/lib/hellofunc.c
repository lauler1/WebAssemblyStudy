#include <stdio.h>
#include "hellomake.h"
#include <emscripten.h>
#define SIZE 5000
char dummy[SIZE] = {};

void myPrintHelloMake(void) {

  printf("Hello from side module! :)\n");

  return;
}
