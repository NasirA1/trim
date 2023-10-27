cmake_minimum_required(VERSION 3.12)
project(conan_tut)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE ${CONAN_LIBS})
