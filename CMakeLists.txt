cmake_minimum_required(VERSION 3.20.0)

project(toolslib)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE NEVER)

add_subdirectory(lib)
add_subdirectory(example)

set_property(DIRECTORY PROPERTY VS_STARTUP_PROJECT example)