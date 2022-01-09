#include "Context.h"
#include "Vertex.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

namespace OpenGL {

	Context::Context(GLFWwindow* window)
		: window(window)
	{
		glfwMakeContextCurrent(window);
		gladLoadGL();
		
		glClearColor(0.15f, 0.15f, 0.15f, 1);
	}

	Context::~Context()
	{
		delete va;
	    delete vb;
	    delete ib;
	    delete shader;
	}

	void Context::draw()
	{
		renderer.clear();

		// Resize Window
		int width, height;
		glfwGetFramebufferSize(window, &width, &height);
		glViewport(0, 0, width, height);

        // Orthographic Camera
        // TODO: Recalculate on window scale event!
        glm::mat4 projection = glm::ortho(0.0f, (float)width, 0.0f, (float)height, -1.0f, 1.0f);
        shader->setUniformMat4("u_MVP", projection);

		// Render
		renderer.draw(va, ib, shader);
		glfwSwapBuffers(window);
	}

	void Context::makeQuad()
	{
		Vertex positions[] = {
			{ 100.0f, 100.0f },
			{ 200.0f, 100.0f },
			{ 200.0f, 200.0f },
			{ 100.0f, 200.0f }
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
        shader = new Shader("basic");
        shader->setUniformColor4f("u_Color", 0xFF7F50);

        // Clean-up
		va->unbind();

		glUseProgram(0);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}
}
