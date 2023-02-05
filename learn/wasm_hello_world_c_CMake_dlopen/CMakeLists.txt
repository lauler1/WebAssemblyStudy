cmake_minimum_required(VERSION "3.24.3")

project("WasmHelloWorldCMake" VERSION 1.0)

set(CMAKE_VERBOSE_MAKEFILE ON)

# Add recursively all the source sunbdirs. Each one shall have CMakeLists.txt
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/src/lib)
add_executable(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/src/hellomake.c)

if (EMSCRIPTEN)
	message("This is EMSCRIPTEN main")
	set(CMAKE_EXECUTABLE_SUFFIX ".js")
	target_link_options("${PROJECT_NAME}" PUBLIC -s MAIN_MODULE=1)
	set_source_files_properties(src/hellomake.c PROPERTIES COMPILE_FLAGS "-fPIC -g")

else ()
	message("This is NATIVE main")

endif ()

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

