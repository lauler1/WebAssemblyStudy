project(mylibfile)

if (EMSCRIPTEN)
	message("This is EMSCRIPTEN lib")
	add_executable(mylibfile hellofunc.c)
	set_source_files_properties(hellofunc.c PROPERTIES COMPILE_FLAGS "-fPIC -g")
	target_link_options(mylibfile PUBLIC -s SIDE_MODULE=1)
	set_target_properties(mylibfile PROPERTIES OUTPUT_NAME "libmylibfile"  SUFFIX ".wasm")
else ()
	message("This is NATIVE lib")
	add_library(mylibfile SHARED hellofunc.c)
endif()

target_include_directories(mylibfile PUBLIC ${CMAKE_SOURCE_DIR}/include)

if (EMSCRIPTEN)
    install(FILES
        "${CMAKE_CURRENT_BINARY_DIR}/libmylibfile.wasm"
        DESTINATION ${CMAKE_SOURCE_DIR}/bin)
else()
	install(TARGETS mylibfile DESTINATION ${CMAKE_SOURCE_DIR}/bin)
endif()

