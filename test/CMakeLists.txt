cmake_minimum_required(VERSION 3.13)
project(cats3_tests VERSION 1.0)
set(CMAKE_CXX_STANDARD 14)

set(SOURCE 
    src/main.cpp
    src/string_util_tests.cpp
)

add_executable(${PROJECT_NAME} ${SOURCE})

target_include_directories(${PROJECT_NAME}
    PUBLIC ${PROJECT_BINARY_DIR}
    PUBLIC ${CMAKE_SOURCE_DIR}/include
    PUBLIC external/gtest/include
    PUBLIC external/gmock/include
)

target_link_directories(${PROJECT_NAME}
    PRIVATE external/googletest/src
)

target_link_libraries(${PROJECT_NAME} cats3 gtest gmock)

install(TARGETS ${PROJECT_NAME} DESTINATION bin)
