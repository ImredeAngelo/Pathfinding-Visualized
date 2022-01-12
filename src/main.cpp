#include <iostream>
#include <Engine/OpenGL/Renderer.h>
#include <Engine/Window.h>

int main(int c, char** argv) {
    Window window{1920, 1080, "Jump Point Search and Goal Bounding"};
    OpenGL::Renderer renderer{window};

    while(!window.shouldClose())
    {
        renderer.beginFrame();
        renderer.drawQuad(-0.5f, -0.5f, 1.0f, 0xFFAC1C);
        renderer.endFrame();
        window.update();
    }

    return 0;
}
