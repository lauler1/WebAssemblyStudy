project(mylibfile)



if (EMSCRIPTEN)
	# add_library(mylibfile OBJECT hellofunc.c)
	add_executable(mylibfile hellofunc.c)

	message("This is EMSCRIPTEN lib")
	set_source_files_properties(hellofunc.c PROPERTIES LINK_FLAGS "-s SIDE_MODULE=1")
	target_link_options(mylibfile PUBLIC -s SIDE_MODULE=1)
	#set_target_properties(mylibfile PROPERTIES PREFIX "" OUTPUT_NAME "mylibfile"  SUFFIX ".wasm")



#set_target_properties(  a  PROPERTIES  OUTPUT_NAME "myname"  SUFFIX ".myext")
else ()
	add_library(mylibfile SHARED hellofunc.c)
endif()

target_include_directories(mylibfile PUBLIC ${CMAKE_SOURCE_DIR}/include)

if (EMSCRIPTEN)
    install(FILES
        "${CMAKE_CURRENT_BINARY_DIR}/mylibfile.wasm"
        DESTINATION ${CMAKE_SOURCE_DIR}/bin)
else()
	install(TARGETS mylibfile DESTINATION ${CMAKE_SOURCE_DIR}/bin)
endif()

