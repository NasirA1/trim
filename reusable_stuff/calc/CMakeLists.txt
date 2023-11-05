cmake_minimum_required(VERSION 3.5)
project(calc)
set(CMAKE_CXX_STANDARD 14)

# header-only library
add_library(${PROJECT_NAME} INTERFACE)

target_include_directories(${PROJECT_NAME} INTERFACE include)

install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/include/arithmetic.h"
    DESTINATION include/${PROJECT_NAME}
)
