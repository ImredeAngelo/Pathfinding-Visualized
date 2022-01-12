#pragma once

#include <string>
#include <glm/mat4x4.hpp>

namespace OpenGL {

    class Shader
    {
    public:
        Shader(const std::string&& shader);
        ~Shader();

        void bind() const;

//        void setUniformColor4f(const std::string& name, Color color);
//        void setUniform4f(const std::string& name, float a, float b, float c, float d) const;
        void setUniformMat4(const std::string& name, glm::mat4 matrix) const;

    private:
        unsigned int compile(unsigned int type, const std::string &source);
        unsigned int create(const std::string& vertexShader, const std::string& fragmentShader);
        std::string parse(const std::string& path);

        unsigned int program;
    };

}