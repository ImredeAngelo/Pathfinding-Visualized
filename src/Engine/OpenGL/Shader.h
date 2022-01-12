#pragma once

#include <string>

namespace OpenGL::Shader {

    unsigned int fromFile(const std::string& path);
    void bind(unsigned int program);
    void destroy(unsigned int program);

}