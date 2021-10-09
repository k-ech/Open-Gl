#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>

int main()
{
	GLFWwindow* window;

	if (!glfwInit())
	{
		return -1;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	/* declare window object (window meta data obj) */
	window = glfwCreateWindow(500, 500, "title", NULL, NULL);
	if (window == NULL)
	{
		return -1;
	}

	glfwMakeContextCurrent(window);

        /* Rendering loop */
        while (!glfwWindowShouldClose(window))
	{

		/* Render here */
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		/* Render here */

		glfwSwapBuffers(window);
		glfwPollEvents();

	}

	glfwTerminate();
    return 0;
}
