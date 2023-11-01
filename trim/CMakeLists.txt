cmake_minimum_required(VERSION 3.13)
project(root)

if (NOT TARGET calc)
  add_subdirectory(calc)
endif ()

if (NOT TARGET util)
  add_subdirectory(util)
endif ()

if (NOT TARGET ai)
  add_subdirectory(ai)
endif ()
