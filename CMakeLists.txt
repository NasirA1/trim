cmake_minimum_required(VERSION 3.13)
project(cats3 VERSION 1.0)
set(CMAKE_CXX_STANDARD 14)

add_library(${PROJECT_NAME} src/string_util.cpp)


############## DOWNLOAD ALL THE GitHub SUBMODULES
find_package(Git QUIET)
if(GIT_FOUND AND EXISTS "${PROJECT_SOURCE_DIR}/.git")
# Update submodules as needed
    option(GIT_SUBMODULE "Check submodules during build" ON)
    if(GIT_SUBMODULE)
        message(STATUS "Submodule update")
        execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive
            WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
            RESULT_VARIABLE GIT_SUBMOD_RESULT
        )
        if(NOT GIT_SUBMOD_RESULT EQUAL "0")
            message(FATAL_ERROR "git submodule update --init failed with ${GIT_SUBMOD_RESULT}! Please checkout submodules.")
        endif()
    endif()
endif()
# CHECK ALL SUBMODULES
if(NOT EXISTS ${PROJECT_SOURCE_DIR}/external/fmt/CMakeLists.txt)
    message(FATAL_ERROR "The fmt submodule was not downloaded! GIT_SUBMODULE was turned off or failed. Please update submodules.")
endif()
#############################################################


add_subdirectory(external/fmt)
add_subdirectory(external/googletest)
add_subdirectory(test)

target_include_directories(${PROJECT_NAME}
    PUBLIC ${PROJECT_BINARY_DIR}
    PUBLIC include
    PUBLIC external/fmt/include
)

target_link_directories(${PROJECT_NAME}
    PRIVATE external/fmt/src
)

target_link_libraries(${PROJECT_NAME} fmt)


add_executable(${PROJECT_NAME}_app src/main.cpp)
target_include_directories(${PROJECT_NAME}_app
    PUBLIC ${PROJECT_BINARY_DIR}
)

target_link_libraries(${PROJECT_NAME}_app ${PROJECT_NAME})


install(TARGETS ${PROJECT_NAME} DESTINATION lib)
install(TARGETS ${PROJECT_NAME}_app DESTINATION bin)


enable_testing()
add_test(NAME "Cats3Tests" COMMAND cats3_tests WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR/test})