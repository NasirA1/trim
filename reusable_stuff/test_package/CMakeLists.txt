cmake_minimum_required(VERSION 3.5)
project(reusable_stuff_package_test CXX)

find_package(reusable_stuff REQUIRED)

add_executable(example src/example.cpp)
target_link_libraries(example reusable_stuff::ai reusable_stuff::calc reusable_stuff::util)

add_executable(example2 src/example2.cpp)
target_link_libraries(example2 reusable_stuff::calc reusable_stuff::util)
