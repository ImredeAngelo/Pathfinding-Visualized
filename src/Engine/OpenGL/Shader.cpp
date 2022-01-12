#include <glad/glad.h>
#include <fstream>
#include <sstream>
#include <iostream>
#include "Shader.h"

//void setUniformMat4(const std::string& name, const glm::mat4 matrix) const
//{
//    int location = glGetUniformLocation(program, name.c_str());
//    if (location != -1)
//    {
//        glUniformMatrix4fv(location, 1, GL_FALSE, &matrix[0][0]);
//    }
//}

unsigned int compile(unsigned int type, const std::string &source)
{
    unsigned int id = glCreateShader(type);
    const char *src = source.c_str();

    glShaderSource(id, 1, &src, nullptr);
    glCompileShader(id);

    int result;
    glGetShaderiv(id, GL_COMPILE_STATUS, &result);
    if (result == GL_FALSE) {
        int length;
        glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
        char *message = (char *) alloca(length * sizeof(char));
        glGetShaderInfoLog(id, length, &length, message);

        std::cout << "Failed to compile " << (type == GL_VERTEX_SHADER ? "vertex" : "fragment") << " shader!"
                  << std::endl << message;

        glDeleteShader(id);
        return 0;
    }

    return id;
}

unsigned int create(const std::string &vertexShader, const std::string &fragmentShader)
{
    unsigned int pr = glCreateProgram();
    unsigned int vs = compile(GL_VERTEX_SHADER, vertexShader);
    unsigned int fs = compile(GL_FRAGMENT_SHADER, fragmentShader);

    glAttachShader(pr, vs);
    glAttachShader(pr, fs);
    glLinkProgram(pr);
    glValidateProgram(pr);

    glDeleteShader(vs);
    glDeleteShader(fs);

    return pr;
}

// TODO: Read files with C
std::string parse(const std::string &path)
{
    std::ifstream stream(path);
    std::stringstream buffer;
    buffer << stream.rdbuf();
    return buffer.str();
}

unsigned int OpenGL::Shader::fromFile(const std::string &path)
{
    const std::string vertexShader = parse("res/shaders/" + path + ".vert");
    const std::string fragmentShader = parse("res/shaders/" + path + ".frag");
    return create(vertexShader, fragmentShader);
}

void OpenGL::Shader::bind(unsigned int program)
{
    glUseProgram(program);
}

void OpenGL::Shader::destroy(unsigned int program)
{
    glDeleteProgram(program);
}
