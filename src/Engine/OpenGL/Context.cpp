#include "Context.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <Engine/OpenGL/Shaders.h>

namespace OpenGL {
	struct Vertex
	{
		float x, y;
	}; 

	Context::Context(GLFWwindow* window)
		: window(window), program(0)
	{
		glfwMakeContextCurrent(window);
		gladLoadGL();
		
		glClearColor(0.15f, 0.15f, 0.15f, 1);
	}

	Context::~Context()
	{
		glDeleteProgram(program);
	}

	void Context::draw()
	{
		int width, height;
		glfwGetFramebufferSize(window, &width, &height);
		glViewport(0, 0, width, height);

		glClear(GL_COLOR_BUFFER_BIT);

		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);

		glfwSwapBuffers(window);
	}

	void Context::makeQuad()
	{
		Vertex positions[] = {
			{ -0.5f, -0.5f },
			{  0.5f, -0.5f },
			{  0.5f,  0.5f },
			{ -0.5f,  0.5f }
		};

		unsigned int indices[] = {
			0, 1, 2,
			2, 3, 0,
		};

		unsigned int buffer;
		glGenBuffers(1, &buffer);
		glBindBuffer(GL_ARRAY_BUFFER, buffer);
		glBufferData(GL_ARRAY_BUFFER, 6 * 2 * sizeof(float), positions, GL_STATIC_DRAW);

		const int positionAttribute = 0;
		glEnableVertexAttribArray(positionAttribute);
		glVertexAttribPointer(positionAttribute, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);

		unsigned int ibo;
		glGenBuffers(1, &ibo);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

        const std::string vertexShader = parseShader("res/shaders/basic.vert");
        const std::string fragmentShader = parseShader("res/shaders/basic.frag");
		program = createShader(vertexShader, fragmentShader);
		glUseProgram(program);
	}
}
