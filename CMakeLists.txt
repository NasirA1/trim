cmake_minimum_required(VERSION 3.13)
project(trim)
set(CMAKE_CXX_STANDARD 14)

set(SOURCE src/main.cpp)

add_executable(${PROJECT_NAME} ${SOURCE})

#target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/string_helper/inc)
#target_link_directories(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/string_helper/build)

target_link_libraries(${PROJECT_NAME} PRIVATE string_helper)

install(TARGETS ${PROJECT_NAME} DESTINATION bin)
