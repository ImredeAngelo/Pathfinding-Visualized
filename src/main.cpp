#include <iostream>
#include <Engine/OpenGL/Renderer.h>
#include <Engine/Window.h>
#include <Pathfinding/Grid.h>

int main(int c, char** argv) {
    constexpr int w = 1920;
    constexpr int h = 1080;

    Window window{w, h, "Jump Point Search and Goal Bounding"};
    Camera camera{w, h};
    OpenGL::Renderer renderer{camera};

    Grid grid(100);

    while(!window.shouldClose())
    {
        renderer.beginFrame();

        for(const auto& node : (Nodes)grid)
            renderer.drawQuad(node.x * 100, node.y * 100, 95.0f, node.color);

        renderer.endFrame();

        window.update();
        Events::process();
    }

    return 0;
}
