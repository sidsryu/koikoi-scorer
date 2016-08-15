project(koikoi-scorer)

cmake_minimum_required(VERSION 2.4)

set(CMAKE_CONFIGURATION_TYPES Debug Release)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

add_subdirectory(src)
add_subdirectory(test)

