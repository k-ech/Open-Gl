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

	//~~~~~~~~~~~~ Vertex Buffer
	/* Make bertex buffer (Triangle test vertex data) */
	float vertices[9] = {
		-0.5f, -0.5f, 0.0f,
		 0.5f, -0.5f, 0.0f,
		 0.0f,  0.5f, 0.0f
	};

	/* Declare vertex buffer object */
	unsigned int VBO;
	glGenBuffers(1, &VBO);

	/* Bind and set buffer data to gl array buffer target */
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	//~~~~~~~~~~~~ Vertex Shader
	/* Right shader script */
	const char* vertexShaderSource = "#version 330 core\n"
		"layout(location = 0) in vec3 aPos;\n"
		"void main()\n"
		"{\n"
		" gl_Position = vec4(aPos.x, aPos.y, aPos.z, 0.1)\n"
		"}\0";

	/* Declare shader object */
	unsigned int vertexShader;
	vertexShader = glCreateShader(GL_VERTEX_SHADER);

	/* Set shader source code to be stores in the shader object */
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);

	/* Compile said vertex shader */
	glCompileShader(vertexShader);

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
