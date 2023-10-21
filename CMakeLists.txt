cmake_minimum_required(VERSION 3.13)
project(trim VERSION 1.0)
set(CMAKE_CXX_STANDARD 14)
configure_file(inc/trim_config.h.in trim_config.h)

set(SOURCE src/main.cpp)

add_executable(${PROJECT_NAME} ${SOURCE})

add_subdirectory(string_helper)


############## DOWNLOAD ALL THE GitHub SUBMODULES
find_package(Git QUIET)
if(GIT_FOUND AND EXISTS "${PROJECT_SOURCE_DIR}/.git")
# Update submodules as needed
    option(GIT_SUBMODULE "Check submodules durin#define trim_VERSION_MAJOR  @trim_VERSION_MAJOR@g build" ON)
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
if(NOT EXISTS ${PROJECT_SOURCE_DIR}/external/glfw/CMakeLists.txt)
    message(FATAL_ERROR "The glfw submodules was not downloaded! GIT_SUBMODULE was turned off or failed. Please update submodules.")
endif()
#############################################################


target_include_directories(${PROJECT_NAME}
    PUBLIC ${PROJECT_BINARY_DIR}
    PUBLIC string_helper
)

target_link_directories(${PROJECT_NAME}
    PRIVATE string_helper
)

target_link_libraries(${PROJECT_NAME} string_helper)

install(TARGETS ${PROJECT_NAME} DESTINATION bin)
