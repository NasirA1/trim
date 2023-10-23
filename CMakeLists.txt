cmake_minimum_required(VERSION 3.13.4)
project(tester)

# Use find_package to locate and configure the Boost C++ Libraries
find_package(Boost REQUIRED)

# Check if Boost was found
if(Boost_FOUND)
    message("Boost found!")
    message("Boost include directories: ${Boost_INCLUDE_DIRS}")
    message("Boost libraries: ${Boost_LIBRARIES}")
else()
    message(FATAL_ERROR "Boost not found. Please install it or provide Boost's CMake configuration.\nHint: sudo apt-get install libboost-dev")
endif()

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} pthread)
