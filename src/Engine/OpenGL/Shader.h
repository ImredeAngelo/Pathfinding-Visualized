#pragma once

#include <string>
#include <glm/glm.hpp>

namespace OpenGL::Shader {

    unsigned int fromFile(const std::string& path);
    void bind(unsigned int program);
    void destroy(unsigned int program);
    void setUniformMat4(unsigned int program, const std::string& name, const glm::mat4& matrix);

}