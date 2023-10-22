cmake_minimum_required(VERSION 3.13)
project(string_helper)
set(CMAKE_CXX_STANDARD 14)

set(SOURCE src/string_helper.cpp)

add_library(${PROJECT_NAME} ${SOURCE})

target_include_directories(${PROJECT_NAME}
    PUBLIC inc
    PRIVATE ${PROJECT_SOURCE_DIR}/../calc/inc
)

target_link_directories(${PROJECT_NAME}
    PRIVATE calc
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE calc
)

set_target_properties(${PROJECT_NAME} PROPERTIES PUBLIC_HEADER inc/string_helper.h)
install(TARGETS ${PROJECT_NAME} 
    LIBRARY DESTINATION lib
    PUBLIC_HEADER DESTINATION include/${PROJECT_NAME}
)
