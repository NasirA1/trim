cmake_minimum_required(VERSION 3.13.4)
project(tester)

add_executable(${PROJECT_NAME} main.cpp)

find_library(GTEST_LIB gtest)
if(${GTEST_LIB} STREQUAL GTEST_LIB-NOTFOUND)
    message(FATAL_ERROR "ERROR: Unable to find googletest library. Clone, build and install it.")
else()
    get_filename_component(GTEST_LIB_LOCATION ${GTEST_LIB} DIRECTORY)
    message(STATUS "googletest library found in: ${GTEST_LIB_LOCATION}")
    target_include_directories(${PROJECT_NAME} PRIVATE ${GTEST_LIB_LOCATION}/../../include)
    target_link_libraries(${PROJECT_NAME} ${GTEST_LIB} pthread)
endif()


enable_testing()
add_test(NAME "TesterTests" COMMAND tester WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
