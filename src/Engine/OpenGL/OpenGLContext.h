#pragma once

struct GLFWwindow;

class OpenGLContext
{
public:
	OpenGLContext(GLFWwindow* window);

	void init();
	void swapBuffers();

private:
	GLFWwindow* window;
};
