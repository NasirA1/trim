cmake_minimum_required(VERSION 3.13)
project(calc)
set(CMAKE_CXX_STANDARD 14)

# header-only library
add_library(${PROJECT_NAME} INTERFACE)

target_include_directories(${PROJECT_NAME} INTERFACE include)

set_target_properties(${PROJECT_NAME} PROPERTIES 
    PUBLIC_HEADER "include/arithmetic.h;"
)
install(TARGETS ${PROJECT_NAME} 
    PUBLIC_HEADER DESTINATION include/${PROJECT_NAME}
)
