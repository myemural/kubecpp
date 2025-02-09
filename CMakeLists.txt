cmake_minimum_required(VERSION 3.24)
set(PACKAGE_NAME "kubecpp")
project(${PACKAGE_NAME} LANGUAGES CXX)

set(PROJECT_VERSION_MAJOR 0)
set(PROJECT_VERSION_MINOR 1)
set(PROJECT_VERSION_PATCH 0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} "${CMAKE_BINARY_DIR}/generators")
set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} "${CMAKE_BINARY_DIR}/Debug/generators") # For Linux
set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} "${CMAKE_BINARY_DIR}/Release/generators") # For Linux

# Settings
option(BUILD_SHARED_LIBS "Build using shared libraries" OFF)
option(BUILD_TESTS "Build tests" OFF)
option(BUILD_EXAMPLES "Build examples" ON)

## Build type processing
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Debug")
endif()

## Compiler and linker related options
if(MSVC)
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++17 /permissive- /W4 /D_CRT_SECURE_NO_WARNINGS")
    if (CMAKE_BUILD_TYPE STREQUAL "Debug")
        set(CMAKE_CXX_FLAGS_DEBUG "/Zi /Zf /Ob2 /Od /RTC1")
    elseif (CMAKE_BUILD_TYPE STREQUAL "Release")
        set(CMAKE_CXX_FLAGS_RELEASE "/Os /Ob2 /DNDEBUG")
    endif()
else()
    add_compile_options("-std=c++17")
endif()

add_subdirectory(src)

add_library(${PACKAGE_NAME})
target_link_libraries(${PACKAGE_NAME} PUBLIC kubecpp_objs)

### Examples
if(BUILD_EXAMPLES)
    add_subdirectory(examples/create_pod)
endif()

### Tests
if(BUILD_TESTS)
    enable_testing()
    add_subdirectory(test)
endif()
