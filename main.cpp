#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>

int main(int argc, char const *argv[])
{
    GLFWwindow *window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    /* GlewInit() should be initialized after context has been set */
    if (glewInit() != GLEW_OK)
    {
        std::cout << "ERROR: glewInit()" << '\n';
    }

    // Check version of openGL we are using
    std::cout << glGetString(GL_VERSION) << '\n';

    float positions[6] = {
        -0.5f, -0.5,
        0.0f, 0.5f,
        0.5f, -0.5f};

    unsigned int buffer;                   // To store id of buffer
    glGenBuffers(1, &buffer);              // Generate 1 buffer
    glBindBuffer(GL_ARRAY_BUFFER, buffer); // What kind of buffer and the ID
    // But where is size of buffer?
    // Copying data to buffer
    glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), positions, GL_STATIC_DRAW);

    glEnableVertexAttribArray(0); // Enable the vertex
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        // Draw what's we have bounded earlier
        glDrawArrays(GL_TRIANGLES, 0, 3);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}