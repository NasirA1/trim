# find_path(trim_INCLUDE_DIR NAMES zlib.h PATHS ${CONAN_INCLUDE_DIRS_trim})
# find_library(trim_LIBRARY NAMES ${CONAN_LIBS_trim} PATHS ${CONAN_LIB_DIRS_trim})

# set(trim_FOUND TRUE)
# set(trim_INCLUDE_DIRS ${trim_INCLUDE_DIR})
# set(trim_LIBRARIES ${trim_LIBRARY})
# mark_as_advanced(trim_LIBRARY trim_INCLUDE_DIR)

# Define the Findtrim.cmake module

# Ensure this module is not loaded more than once in the same CMake run
set(trim_FOUND FALSE)
message(STATUS "Searching for trim ...")
if(NOT trim_FOUND)
    set(trim_FOUND TRUE)

    # Search for trim library
    find_path(trim_INCLUDE_DIR NAMES xxx.h PATH_SUFFIXES xxx)
    find_library(trim_LIBRARY NAMES xxx)

    # Check if trim library and its components are found
    if(trim_LIBRARY AND trim_INCLUDE_DIR)
        set(trim_FOUND TRUE)

        # Set the library and its components
        set(trim_LIBRARIES ${trim_LIBRARY})
        set(trim_INCLUDE_DIRS ${trim_INCLUDE_DIR})

        # List of components
        set(trim_COMPONENTS ai calc util)

        # Set the components as imported targets
        foreach(component ${trim_COMPONENTS})
            add_library(trim::${component} INTERFACE IMPORTED)
            target_link_libraries(trim::${component} INTERFACE ${trim_LIBRARIES})
            target_include_directories(trim::${component} INTERFACE ${trim_INCLUDE_DIRS})
        endforeach()

        # Provide information about trim library and its components
        message(STATUS "trim library found:")
        message(STATUS "  trim_INCLUDE_DIRS: ${trim_INCLUDE_DIRS}")
        message(STATUS "  trim_LIBRARIES: ${trim_LIBRARIES}")
        message(STATUS "  trim_COMPONENTS: ${trim_COMPONENTS}")

    else()
        # Library or its components not found
        set(trim_FOUND FALSE)
        message(STATUS "OOPS! trim library and/or components not found.")cmake_find_package
    endif()
endif()
