cmake_minimum_required(VERSION 3.13)
project(trim_test)
set(CMAKE_CXX_STANDARD 14)

add_executable(${PROJECT_NAME} main.cpp)

target_include_directories(${PROJECT_NAME} PRIVATE calc/include util/include)
target_link_libraries(${PROJECT_NAME} PRIVATE util)

install(TARGETS ${PROJECT_NAME} DESTINATION bin)

add_subdirectory(calc)
add_subdirectory(util)
add_subdirectory(ai)
