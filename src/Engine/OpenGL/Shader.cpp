#include "Shader.h"
#include <glad/glad.h>
#include <iostream>
#include <fstream>
#include <sstream>

namespace OpenGL {

    Shader::Shader(const std::string &&shader)
    {
        const std::string vertexShader = parse("res/shaders/" + shader + ".vert");
        const std::string fragmentShader = parse("res/shaders/" + shader + ".frag");
        program = create(vertexShader, fragmentShader);
    }

    Shader::~Shader()
    {
        glDeleteProgram(program);
    }

    void Shader::bind() const
    {
        glUseProgram(program);
    }

//    void Shader::setUniformColor4f(const std::string &name, Color color)
//    {
//        setUniform4f(name, color.r, color.g, color.b, 1.0f);
//    }

//    void Shader::setUniform4f(const std::string& name, float a, float b, float c, float d) const
//    {
//        int location = glGetUniformLocation(program, name.c_str());
//        if (location != -1)
//        {
//            glUniform4f(location, a, b, c, d);
//        }
//    }

    void Shader::setUniformMat4(const std::string& name, const glm::mat4 matrix) const
    {
        int location = glGetUniformLocation(program, name.c_str());
        if (location != -1)
        {
            glUniformMatrix4fv(location, 1, GL_FALSE, &matrix[0][0]);
        }
    }

    unsigned int Shader::compile(unsigned int type, const std::string &source)
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

    unsigned int Shader::create(const std::string &vertexShader, const std::string &fragmentShader)
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
    std::string Shader::parse(const std::string &path)
    {
        std::ifstream stream(path);
        std::stringstream buffer;
        buffer << stream.rdbuf();
        return buffer.str();
    }

}