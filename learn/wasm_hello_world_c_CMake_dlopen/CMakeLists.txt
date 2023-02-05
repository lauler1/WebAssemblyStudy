cmake_minimum_required(VERSION "3.24.3")


project("WasmHelloWorldCMake" VERSION 1.0)

set(CMAKE_VERBOSE_MAKEFILE ON)

message(">>> EMSCRIPTEN = ${EMSCRIPTEN}")
if (EMSCRIPTEN)
  message("This is EMSCRIPTEN")
# CFLAGS+= -sLLD_REPORT_UNDEFINED #to get more information on undefined symbols
# CFLAGS+= -sERROR_ON_UNDEFINED_SYMBOLS=0 #To disable errors for undefined symbols

else ()
  message("This is not EMSCRIPTEN")

endif ()

#set(CMAKE_CXX_STANDARD 17)
#set(CMAKE_CXX_STANDARD_REQUIRED ON  )
# append flag, best practice, suggested, don't lose previously defined flags
# set(CMAKE_CXX_FLAGS " ${CMAKE_CXX_FLAGS} -Wall -g ")
#add_compile_options(-Wall -g)

# Add recursively all the source sunbdirs. Each one shall have CMakeLists.txt
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/src/lib)

if (EMSCRIPTEN)
    # set(CMAKE_CXX_FLAGS " ${CMAKE_CXX_FLAGS} -s SIDE_MODULE=1 ")
	message("This is EMSCRIPTEN main")
	add_compile_options(-s MAIN_MODULE=1)
	set(CMAKE_EXECUTABLE_SUFFIX ".js")
	
	set_source_files_properties(src/hellomake.c PROPERTIES LINK_FLAGS "-s MAIN_MODULE=1")
	set_source_files_properties(src/hellomake.c PROPERTIES COMPILE_FLAGS "-s MAIN_MODULE=1")
	
	#add_compile_options(-s MAIN_MODULE=1 -s ASYNCIFY -s "ASYNCIFY_IMPORTS=['doLoadLibrary']" -s FORCE_FILESYSTEM=1 -s "EXTRA_EXPORTED_RUNTIME_METHODS=['FS']")
endif()

add_executable(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/src/hellomake.c)

#target_link_libraries("${PROJECT_NAME}" PUBLIC mylibfile)
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
	# install(TARGETS mylibfile DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/bin)
endif()

