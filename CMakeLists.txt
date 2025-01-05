cmake_minimum_required(VERSION 3.24)
set(PACKAGE_NAME "kubecpp")
project(${PACKAGE_NAME} LANGUAGES CXX)

set(PROJECT_VERSION_MAJOR 0)
set(PROJECT_VERSION_MINOR 1)
set(PROJECT_VERSION_PATCH 0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} "${CMAKE_BINARY_DIR}/generators")

# Settings
option(BUILD_SHARED_LIBS "Build using shared libraries" OFF)
option(BUILD_TESTS "Build tests" OFF) # Not used for now
option(BUILD_EXAMPLES "Build examples" ON)

## Build type processing
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Debug")
endif()

## Compiler and linker related options
if(MSVC)
    add_compile_options("/std:c++17")
else()
    add_compile_options("-std=c++17")
endif()

add_subdirectory(src)

add_library(${PACKAGE_NAME})
target_link_libraries(${PACKAGE_NAME} PUBLIC kubecpp_objs)

if(BUILD_EXAMPLES)
    add_subdirectory(examples/create_pod)
endif()

### Tests

##################
