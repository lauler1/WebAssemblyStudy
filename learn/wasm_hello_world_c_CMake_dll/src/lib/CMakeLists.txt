project(myLib)

if (EMSCRIPTEN)
	add_library(mylibfile hellofunc.c)

	message("This is EMSCRIPTEN lib")
	add_compile_options(-s SIDE_MODULE=1)
	set_target_properties(mylibfile PROPERTIES SUFFIX ".wasm")
	set_target_properties(mylibfile PROPERTIES PREFIX "")
else ()
	add_library(mylibfile SHARED hellofunc.c)
endif()

target_include_directories(mylibfile PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../../include)

if (EMSCRIPTEN)
    install(FILES
        "${CMAKE_CURRENT_BINARY_DIR}/mylibfile.wasm"
        DESTINATION ${CMAKE_SOURCE_DIR}/bin)
else()
	install(TARGETS mylibfile DESTINATION ${CMAKE_SOURCE_DIR}/bin)
endif()

