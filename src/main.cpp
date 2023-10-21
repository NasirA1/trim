#include <iostream>
#include <sstream>
#include "string_helper.h"
#include <GLFW/glfw3.h>
#include "trim_config.h"


int main(int argc, char* argv[])
{    
    const auto joined = string_helper::join(argv + 1, static_cast<size_t>(argc - 1));
    std::cout << string_helper::trim_all(joined) << std::endl;

    std::cout << std::endl << argv[0] << " Version: " << trim_VERSION_MAJOR << "." << trim_VERSION_MINOR << std::endl;

    GLFWwindow* window;
    if( !glfwInit() )
    {
        fprintf( stderr, "Failed to initialize GLFW\n" );
        exit( EXIT_FAILURE );
    }

    window = glfwCreateWindow( 300, 300, "Test: trim", NULL, NULL );
    if (!window)
    {
        fprintf( stderr, "Failed to open GLFW window\n" );
        glfwTerminate();
        exit( EXIT_FAILURE );
    }

 // Main loop
    while( !glfwWindowShouldClose(window) )
    {
        // Swap buffers
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // Terminate GLFW
    glfwTerminate();

    return EXIT_SUCCESS;
}