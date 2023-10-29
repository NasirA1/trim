cmake_minimum_required(VERSION 3.13)
project(ai)
set(CMAKE_CXX_STANDARD 14)

add_library(${PROJECT_NAME} src/adjacency_list.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC include)

set_target_properties(${PROJECT_NAME} PROPERTIES 
    PUBLIC_HEADER "include/adjacency_list.h;"
)
install(TARGETS ${PROJECT_NAME} 
    LIBRARY DESTINATION lib
    PUBLIC_HEADER DESTINATION include/${PROJECT_NAME}
)
