#include <iostream>
#include <Engine/OpenGL/Renderer.h>
#include <Engine/Window.h>
#include <Pathfinding/Grid.h>

int main(int c, char** argv) {
    Window window{1920, 1080, "Jump Point Search and Goal Bounding"};
    OpenGL::Renderer renderer{window};

    Grid grid(100);

    while(!window.shouldClose())
    {
        renderer.beginFrame();

        for(const auto& node : (Nodes)grid)
            renderer.drawQuad(node.x * 100, node.y * 100, 95.0f, node.color);

        renderer.endFrame();
        window.update();
    }

    return 0;
}
