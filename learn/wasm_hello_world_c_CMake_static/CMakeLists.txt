cmake_minimum_required(VERSION "3.24.3")

project("WasmHelloWorldCMake" VERSION 1.0)


message(">>> EMSCRIPTEN = ${EMSCRIPTEN}")
if (EMSCRIPTEN)
  message("This is EMSCRIPTEN")
# CFLAGS+= -sLLD_REPORT_UNDEFINED #to get more information on undefined symbols
# CFLAGS+= -sERROR_ON_UNDEFINED_SYMBOLS=0 #To disable errors for undefined symbols

else ()
  message("This is not EMSCRIPTEN")

endif ()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON  )
# append flag, best practice, suggested, don't lose previously defined flags
set(CMAKE_CXX_FLAGS " ${CMAKE_CXX_FLAGS} -Wall -g ")



#This is the right way, all sources that are not intended to become an
# executable (e.g. no main()) shall become a library
add_library(myLib "")

# Add recursively all the source sunbdirs. Each one shall have CMakeLists.txt
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/src)

add_executable(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/src/hellomake.c)

target_include_directories(myLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries("${PROJECT_NAME}" PUBLIC myLib)
target_include_directories("${PROJECT_NAME}" PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

# CC=emcc
# CFLAGS=-I$(IDIR)

if (EMSCRIPTEN)
    install(FILES
        "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}.js"
        "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}.wasm"
        DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/bin)
else()
	install(TARGETS "${PROJECT_NAME}" DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/bin)
endif()

