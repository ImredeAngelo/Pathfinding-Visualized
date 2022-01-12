#include <iostream>
#include <Engine/OpenGL/Renderer.h>
#include <Engine/Window.h>

int main(int c, char** argv) {
    Window window{1920, 1080, "Jump Point Search and Goal Bounding"};
    OpenGL::Renderer renderer{window};

    while(!window.shouldClose())
    {
        renderer.beginFrame();
        renderer.drawQuad(10, 10, 100, 0xFFAC1C);
        renderer.endFrame();
        window.update();
    }

    return 0;
}
