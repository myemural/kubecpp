cmake_minimum_required(VERSION 3.24)
project(kubecpp-create-pod LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set (CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} "${CMAKE_CURRENT_BINARY_DIR}/generators")

if(MSVC)
    add_compile_options("/std:c++17")
else()
    add_compile_options("-std=c++17")
endif()

add_executable(kubecpp-create-pod main.cpp)

find_package(kubecpp REQUIRED)
target_link_libraries(kubecpp-create-pod kubecpp::kubecpp)