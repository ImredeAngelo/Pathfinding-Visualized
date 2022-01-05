#include "Context.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <string>
#include <iostream>

namespace OpenGL {
	static const struct Vertex
	{
		float x, y;
		float r, g, b;
	}; 

	static unsigned int compileShader(unsigned int type, const std::string& source)
	{
		unsigned int id = glCreateShader(type);
		const char* src = source.c_str();

		glShaderSource(id, 1, &src, NULL);
		glCompileShader(id);

		int result;
		glGetShaderiv(id, GL_COMPILE_STATUS, &result);
		if (result == GL_FALSE)
		{
			int length;
			glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
			char* message = (char*)alloca(length * sizeof(char));
			glGetShaderInfoLog(id, length, &length, message);

			std::cout << "Failed to compile " << (type == GL_VERTEX_SHADER ? "vertex" : "fragment") << " shader!" << std::endl << message;

			glDeleteShader(id);
			return 0;
		}

		// std::cout << "Compiled " << (type == GL_VERTEX_SHADER ? "vertex" : "fragment") << " shader." << std::endl;
		return id;
	}

	static unsigned int createShader(const std::string& vertexShader, const std::string& fragmentShader)
	{
		unsigned int program = glCreateProgram();
		unsigned int vs = compileShader(GL_VERTEX_SHADER, vertexShader);
		unsigned int fs = compileShader(GL_FRAGMENT_SHADER, fragmentShader);

		glAttachShader(program, vs);
		glAttachShader(program, fs);
		glLinkProgram(program);
		glValidateProgram(program);

		glDeleteShader(vs);
		glDeleteShader(fs);

		return program;
	}

	Context::Context(GLFWwindow* window)
		: window(window), buffer(0), program(0)
	{
		glfwMakeContextCurrent(window);
		gladLoadGL();
		
		glClearColor(0.15, 0.15, 0.15, 1);
		// glfwSwapInterval(1);
	}

	/*void Context::makeTraingle()
	{
		typedef unsigned int uint;

		Vertex vertices[3] =
		{
			{ -0.6f, -0.4f, 1.f, .35f, 0.f },
			{  0.6f, -0.4f, 1.f, .35f, 0.f },
			{   0.f,  0.6f, 1.f, .35f, 0.f }
		};

		glGenBuffers(1, &vertex_buffer);
		glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		uint vertex_shader = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertex_shader, 1, &vertex_shader_text, NULL);
		glCompileShader(vertex_shader);

		uint fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragment_shader, 1, &fragment_shader_text, NULL);
		glCompileShader(fragment_shader);

		program = glCreateProgram();
		glAttachShader(program, vertex_shader);
		glAttachShader(program, fragment_shader);
		glLinkProgram(program);

		mvp_location = glGetUniformLocation(program, "MVP");
		vpos_location = glGetAttribLocation(program, "vPos");
		vcol_location = glGetAttribLocation(program, "vCol");

		glEnableVertexAttribArray(vpos_location);
		glVertexAttribPointer(vpos_location, 2, GL_FLOAT, GL_FALSE,
			sizeof(vertices[0]), (void*)0);
		glEnableVertexAttribArray(vcol_location);
		glVertexAttribPointer(vcol_location, 3, GL_FLOAT, GL_FALSE,
			sizeof(vertices[0]), (void*)(sizeof(float) * 2));
	}*/

	void Context::draw()
	{
		int width, height;
		glfwGetFramebufferSize(window, &width, &height);
		glViewport(0, 0, width, height);

		glClear(GL_COLOR_BUFFER_BIT);

		glUseProgram(program);
		glDrawArrays(GL_TRIANGLES, 0, 3);

		glfwSwapBuffers(window);
	}

	void Context::makeQuad()
	{
		const std::string vs = R"glsl(
			#version 330 core

			layout(location = 0) in vec4 position;

			void main(){
			   gl_Position = position;
			}
		)glsl";

		const std::string fs = R"glsl(
			#version 330 core

			void main(){
			   gl_FragColor = vec4(1.0, 0.4, 0.0, 1.0);
			}
		)glsl";

		Vertex positions[3] = {
			{ -0.5f, -0.5f },
			{  0.5f, -0.5f },
			{  0.0f,  0.5f }
		};

		glGenBuffers(1, &buffer);
		glBindBuffer(GL_ARRAY_BUFFER, buffer);
		glBufferData(GL_ARRAY_BUFFER, sizeof(positions), positions, GL_STATIC_DRAW);

		program = createShader(vs, fs);

		const int positionAttribute = 0;
		glEnableVertexAttribArray(positionAttribute);
		glVertexAttribPointer(positionAttribute, 2, GL_FLOAT, GL_FALSE, sizeof(positions[0]), (void*)0);
	}
}
