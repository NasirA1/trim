cmake_minimum_required(VERSION 3.13)
project(trim VERSION 1.0)
set(CMAKE_CXX_STANDARD 14)
configure_file(inc/trim_config.h.in trim_config.h)

option(EMULATION "Emulation Mode" OFF)

if(${EMULATION})
    message(STATUS "Emulation mode is ON.")
    add_definitions(-DEMULATION)
endif()

set(SOURCE src/main.cpp)

add_executable(${PROJECT_NAME} ${SOURCE})

add_subdirectory(calc)
add_subdirectory(string_helper)

target_include_directories(${PROJECT_NAME}
    PRIVATE ${PROJECT_BINARY_DIR}
    PRIVATE string_helper
)

target_link_libraries(${PROJECT_NAME} string_helper)

install(TARGETS ${PROJECT_NAME} DESTINATION bin)
