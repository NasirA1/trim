cmake_minimum_required(VERSION 3.13)
project(trim)
set(CMAKE_CXX_STANDARD 14)

set(SOURCE src/main.cpp)

add_executable(${PROJECT_NAME} ${SOURCE})

add_subdirectory(string_helper)


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
if(NOT EXISTS ${PROJECT_SOURCE_DIR}/external/glfw/CMakeLists.txt)
    message(FATAL_ERROR "The glfw submodules was not downloaded! GIT_SUBMODULE was turned off or failed. Please update submodules.")
endif()
#############################################################


add_subdirectory(external/glfw)

target_include_directories(${PROJECT_NAME}
    PUBLIC string_helper
    PUBLIC external/glfw/include
)

target_link_directories(${PROJECT_NAME}
    PRIVATE string_helper
    PRIVATE external/glfw/src
)

target_link_libraries(${PROJECT_NAME} string_helper glfw)

install(TARGETS ${PROJECT_NAME} DESTINATION bin)
