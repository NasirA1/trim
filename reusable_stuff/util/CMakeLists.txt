cmake_minimum_required(VERSION 3.5)
project(util)
set(CMAKE_CXX_STANDARD 14)

add_library(${PROJECT_NAME} src/string_helper.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC include)

set_target_properties(${PROJECT_NAME} PROPERTIES 
    PUBLIC_HEADER "include/string_helper.h;"
)
install(TARGETS ${PROJECT_NAME} 
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    PUBLIC_HEADER DESTINATION include/${PROJECT_NAME}
)
