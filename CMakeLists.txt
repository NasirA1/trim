cmake_minimum_required(VERSION 3.13)
project(cmake_test)

add_executable(cmake_test main.cpp)

# build-level custom command: make run_custom_command
add_custom_target(run_custom_script
    COMMAND ${CMAKE_COMMAND} -E echo "Running custom script..."
    COMMAND ${CMAKE_COMMAND} -E echo "Custom script completed."
    COMMENT "Running a custom script"
)

message(STATUS "Hello, CMake world!")

# cmake config level custom command
execute_process(
    COMMAND echo "Hello, CMake world!"
    RESULT_VARIABLE result
    OUTPUT_VARIABLE output
    ERROR_VARIABLE error
)

# Check the result of the executed command
if(result EQUAL 0)
    message("Command executed successfully.")
    message("Output: ${output}")
else()
    message("Command failed with error code ${result}")
    message("Error: ${error}")
endif()

