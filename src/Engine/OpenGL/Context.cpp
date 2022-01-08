#include "Context.h"
#include "VertexBuffer.h"
#include "Vertex.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <Engine/OpenGL/Shaders.h>

namespace OpenGL {

	Context::Context(GLFWwindow* window)
		: window(window), program(0)
	{
		glfwMakeContextCurrent(window);
		gladLoadGL();
		
		glClearColor(0.15f, 0.15f, 0.15f, 1);
	}

	Context::~Context()
	{
	    delete vb;
	    delete ib;

		glDeleteProgram(program);
	}

	void Context::draw()
	{
		glClear(GL_COLOR_BUFFER_BIT);
        glUseProgram(program);

		int width, height;
		glfwGetFramebufferSize(window, &width, &height);
		glViewport(0, 0, width, height);

        va->bind();

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

		// TODO: Only use one VAO in program
		va = new VertexArray();
		vb = new VertexBuffer(positions, 4 * sizeof(Vertex));

		VertexBufferLayout layout;
		layout.push<float>(2);
		va->addBuffer(vb, layout);

		ib = new IndexBuffer(indices, 6);

		// Load shaders
        const std::string vertexShader = parseShader("res/shaders/basic.vert");
        const std::string fragmentShader = parseShader("res/shaders/basic.frag");
		program = createShader(vertexShader, fragmentShader);
		// glUseProgram(program);

		// Clean-up
		va->unbind();

		glUseProgram(0);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}
}
