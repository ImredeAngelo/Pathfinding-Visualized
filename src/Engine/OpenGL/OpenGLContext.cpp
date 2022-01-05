#include "OpenGLContext.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>
#include <iostream>

OpenGLContext::OpenGLContext(GLFWwindow* window)
    : window(window)
{
	glfwMakeContextCurrent(window);
	gladLoadGL();
	glfwSwapInterval(1);
}

void OpenGLContext::init()
{
    glClearColor(0.1, 0.1, 0.1, 1);
	
	static const struct
	{
		float x, y;
		float r, g, b;
	} positions[3] =
	{
		{ -0.6f, -0.4f, 1.f, 0.f, 0.f },
		{  0.6f, -0.4f, 0.f, 1.f, 0.f },
		{   0.f,  0.6f, 0.f, 0.f, 1.f }
	};

	unsigned int buffer;
	glGenBuffers(1, &buffer);
	glBindBuffer(GL_ARRAY_BUFFER, buffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(positions), positions, GL_STATIC_DRAW); //GL_STREAM_DRAW

	const int positionAttribute = 0;
	glEnableVertexAttribArray(positionAttribute);
	glVertexAttribPointer(positionAttribute, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), 0);

	const std::string vertexShader =
		"#version 110\n"
		"uniform mat4 MVP;\n"
		"attribute vec3 vCol;\n"
		"attribute vec2 vPos;\n"
		"varying vec3 color;\n"
		"void main()\n"
		"{\n"
		"    gl_Position = MVP * vec4(vPos, 0.0, 1.0);\n"
		"    color = vCol;\n"
		"}\n";

	const std::string fragmentShader =
		"#version 110\n"
		"varying vec3 color;\n"
		"void main()\n"
		"{\n"
		"    gl_FragColor = vec4(color, 1.0);\n"
		"}\n";

	// unsigned int shader = createShader(vertexShader, fragmentShader);
	//glUseProgram(shader);

	while (!glfwWindowShouldClose(window))
	{

		int width, height;
		glfwGetFramebufferSize(window, &width, &height);
		
		glViewport(0, 0, width, height);
		glClear(GL_COLOR_BUFFER_BIT);

		//glUseProgram(shader);

		glDrawArrays(GL_TRIANGLES, 0, 3);
		
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
}

void OpenGLContext::swapBuffers()
{
    glfwSwapBuffers(window);
}
