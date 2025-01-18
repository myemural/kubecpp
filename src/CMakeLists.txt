file(GLOB_RECURSE SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

add_library(kubecpp_objs OBJECT "${SRC_FILES}")
target_include_directories(kubecpp_objs PRIVATE "${CMAKE_SOURCE_DIR}/include")

find_package(cpr REQUIRED)
target_link_libraries(kubecpp_objs cpr::cpr)
    
find_package(ryml REQUIRED)
target_link_libraries(kubecpp_objs ryml::ryml)

find_package(RapidJSON REQUIRED)
target_link_libraries(kubecpp_objs rapidjson)

# Detecting OS and Compiler
message("Detected OS: ${CMAKE_SYSTEM_NAME} ${CMAKE_SYSTEM_VERSION}")
if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
  target_compile_definitions(kubecpp_objs PUBLIC "LINUX_OS")
elseif(CMAKE_SYSTEM_NAME STREQUAL "Windows")
  target_compile_definitions(kubecpp_objs PUBLIC "WINDOWS_OS")
endif()