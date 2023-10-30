cmake_minimum_required(VERSION 3.13)
project(trim_consumer)
set(CMAKE_CXX_STANDARD 14)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(${PROJECT_NAME} src/main.cpp)

find_package(trim REQUIRED COMPONENTS calc util)
if(trim_FOUND)
    message("trim library found.")
else()
    message(FATAL_ERROR "trim library not found!")
endif()

target_link_libraries(${PROJECT_NAME} PRIVATE trim::util trim::calc)

install(TARGETS ${PROJECT_NAME} DESTINATION bin)
