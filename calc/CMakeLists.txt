cmake_minimum_required(VERSION 3.13)
project(calc)
set(CMAKE_CXX_STANDARD 14)

set(SOURCE src/calc.cpp)

add_library(${PROJECT_NAME} ${SOURCE})

target_include_directories(${PROJECT_NAME} PUBLIC inc)

set_target_properties(${PROJECT_NAME} PROPERTIES PUBLIC_HEADER inc/calc.h)
install(TARGETS ${PROJECT_NAME} 
    LIBRARY DESTINATION lib
    PUBLIC_HEADER DESTINATION include/${PROJECT_NAME}
)
