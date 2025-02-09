include_directories("${PROJECT_SOURCE_DIR}/include")

file(GLOB_RECURSE TEST_SRC_FILES "${PROJECT_SOURCE_DIR}/test/*.cpp")
list(REMOVE_ITEM TEST_SRC_FILES "${PROJECT_SOURCE_DIR}/test/main.cpp")

find_package(GTest REQUIRED)

foreach(TEST_SRC_FILE ${TEST_SRC_FILES})
    set(FILE_NAME)
    get_filename_component(FILE_NAME ${TEST_SRC_FILE} NAME_WE)
    add_executable("${FILE_NAME}" ${TEST_SRC_FILE} "${PROJECT_SOURCE_DIR}/test/main.cpp")
    target_include_directories("${FILE_NAME}" PUBLIC "${PROJECT_SOURCE_DIR}/include")
    target_link_libraries("${FILE_NAME}" kubecpp gtest::gtest)
    add_test(NAME ${FILE_NAME} COMMAND "${FILE_NAME}")
endforeach()
