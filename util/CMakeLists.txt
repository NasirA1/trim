cmake_minimum_required(VERSION 3.13)
project(util)
set(CMAKE_CXX_STANDARD 14)

add_library(${PROJECT_NAME} string_helper.cpp)

target_include_directories(${PROJECT_NAME} INTERFACE .)

install(TARGETS ${PROJECT_NAME} DESTINATION lib)
