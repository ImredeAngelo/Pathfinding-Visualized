#include "Context.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <Engine/Vertex.h>

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

	void Context::draw(Camera& camera)
	{
		renderer.clear();

		// Resize Window
		int width, height;
		glfwGetFramebufferSize(window, &width, &height);
		glViewport(0, 0, width, height);
		camera.setProjection(width, height);

		// TODO: Only update when camera moves?
		glm::mat4 model = glm::translate(glm::vec3(100, 100, 0));
		shader->setUniformMat4("u_MVP", camera.getViewMatrix() * model);
		renderer.draw(va, ib, shader);

		glfwSwapBuffers(window);
	}

	void Context::makeQuad()
	{
		Vertex positions[] = {
			{ -50.0f, -50.0f, 0xFFFFFF },
			{  50.0f, -50.0f, 0xFFFFFF },
			{  50.0f,  50.0f, 0xFFFFFF },
			{ -50.0f,  50.0f, 0xFFFFFF },
			{  50.0f, -50.0f, 0xCD7F32 },
			{ 150.0f, -50.0f, 0xCD7F32 },
			{ 150.0f,  50.0f, 0xCD7F32 },
			{  50.0f,  50.0f, 0xCD7F32 },
		};

		unsigned int indices[] = {
			0, 1, 2,
			2, 3, 0,
			4, 5, 6,
			6, 7, 4,
		};

		// TODO: Only use one VAO in program
		va = new VertexArray();
		vb = new VertexBuffer(positions, 8 * sizeof(Vertex));

		VertexBufferLayout layout;
		layout.push<float>(2);
		layout.push<float>(4);
		va->addBuffer(vb, layout);

		ib = new IndexBuffer(indices, 12);

		// Load shaders
        shader = new Shader("basic");
		shader->bind();
//		shader->setUniformColor4f("u_Color", 0xCD7F32);

        // Clean-up
//      shader->unbind();
//      va->unbind();
//		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}

	void Context::makeGrid(unsigned int n, float size)
	{
		// make n x n grid of quads
	}

}
