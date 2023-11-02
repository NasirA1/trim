cmake_minimum_required(VERSION 3.5)
project(trim)

if (NOT TARGET calc)
  add_subdirectory(calc)
endif ()

if (NOT TARGET util)
  add_subdirectory(util)
endif ()

if (NOT TARGET ai)
  add_subdirectory(ai)
endif ()
