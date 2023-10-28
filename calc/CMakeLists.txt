cmake_minimum_required(VERSION 3.13)
project(calc)
set(CMAKE_CXX_STANDARD 14)

# header-only library
add_library(${PROJECT_NAME} INTERFACE)

target_include_directories(${PROJECT_NAME} INTERFACE include)
