cmake_minimum_required(VERSION 3.24)
project(kubecpp-create-pod LANGUAGES CXX)

add_executable(kubecpp-create-pod main.cpp)

target_include_directories(kubecpp-create-pod PUBLIC "${CMAKE_SOURCE_DIR}/include")
target_link_libraries(kubecpp-create-pod PUBLIC kubecpp)