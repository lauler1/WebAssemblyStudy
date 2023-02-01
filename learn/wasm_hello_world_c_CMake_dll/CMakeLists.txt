cmake_minimum_required(VERSION "3.24.3")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON  )
# append flag, best practice, suggested, don't lose previously defined flags
set(CMAKE_CXX_FLAGS " ${CMAKE_CXX_FLAGS} -Wall -g ")

project("WasmHelloWorldCMake" VERSION 1.0)


add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/src)
target_include_directories("${PROJECT_NAME}" PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)



# CC=emcc
# CFLAGS=-I$(IDIR)
# CFLAGS+= -g
# CFLAGS+= -sLLD_REPORT_UNDEFINED #to get more information on undefined symbols
# CFLAGS+= -sERROR_ON_UNDEFINED_SYMBOLS=0 #To disable errors for undefined symbols

install(TARGETS "${PROJECT_NAME}" DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/bin)
