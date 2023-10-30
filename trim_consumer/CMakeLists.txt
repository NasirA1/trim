cmake_minimum_required(VERSION 3.13)
project(trim_consumer)
set(CMAKE_CXX_STANDARD 14)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(${PROJECT_NAME} src/main.cpp)

find_package(trim REQUIRED COMPONENTS calc util)
if(trim_FOUND)
    message("trim library found!")
    message("trim include directories: ${trim_INCLUDE_DIRS}")
    message("trim libraries: ${trim_LIBRARIES}")
else()
    message(FATAL_ERROR "trim library not found!")
endif()

target_include_directories(${PROJECT_NAME} PRIVATE trim::calc trim::util)
target_link_libraries(${PROJECT_NAME} PRIVATE trim::util)

install(TARGETS ${PROJECT_NAME} DESTINATION bin)
