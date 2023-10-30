set(trim_FOUND TRUE)

# List of components
set(trim_COMPONENTS ai calc util)

# Set the components as imported targets
foreach(component ${trim_COMPONENTS})
    add_library(trim::${component} INTERFACE IMPORTED)
    target_include_directories(trim::${component} INTERFACE ${CONAN_TRIM_ROOT}/include/${component})
    if(NOT ${component} STREQUAL "calc")  ## calc is header-only
        target_link_libraries(trim::${component} INTERFACE ${CONAN_TRIM_ROOT}/lib/lib${component}.a)
    endif()    
endforeach()

# Provide information about trim library and its components
message(STATUS "trim library found.")
message(STATUS "  trim_COMPONENTS: ${trim_COMPONENTS}")
