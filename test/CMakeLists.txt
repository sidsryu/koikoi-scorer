set(test_src
    main.cpp
	scoringhands_test.cpp
	instancewins_test.cpp
	koikoiscorer_test.cpp
	optionrules_test.cpp
)

set(cpputest_lib
    ${CMAKE_STATIC_LIBRARY_PREFIX}CppUTest${CMAKE_STATIC_LIBRARY_SUFFIX}
)

set(cpputest_new_macro ${cpputest_home}/include/CppUTest/MemoryLeakDetectorNewMacros.h)
set(cpputest_malloc_macro ${cpputest_home}/include/CppUTest/MemoryLeakDetectorMallocMacros.h)

if (MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /FI\"${cpputest_new_macro}\"")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} /FI\"${cpputest_malloc_macro}\"")
else ()
	set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -include \"${cpputest_malloc_macro}\"")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -include \"${cpputest_new_macro}\"")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -include \"${cpputest_malloc_macro}\"")
endif ()

include_directories(${PROJECT_SOURCE_DIR}/src)
include_directories(${cpputest_home}/include)
link_directories(${cpputest_home}/lib)

add_executable(koikoi-scorer-tests ${test_src})
set_target_properties(koikoi-scorer-tests PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
set_target_properties(koikoi-scorer-tests PROPERTIES RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_CURRENT_BINARY_DIR})
set_target_properties(koikoi-scorer-tests PROPERTIES RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_CURRENT_BINARY_DIR})

if (WIN32)
    target_link_libraries(koikoi-scorer-tests koikoi-scorer ${cpputest_lib} winmm.lib)
else ()
	target_link_libraries(koikoi-scorer-tests koikoi-scorer ${cpputest_lib})
endif ()

add_custom_command(TARGET koikoi-scorer-tests POST_BUILD COMMAND koikoi-scorer-tests)
