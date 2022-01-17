#pragma once

#include <Core/Camera.h>
#include <Engine/OpenGL/Renderer.h>

class Application
{
public:
    Application();

private:
    // TODO: Make procedural
//    OpenGL::Renderer renderer;
    Window window;
    Camera camera;
};
