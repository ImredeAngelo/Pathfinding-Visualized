#include <iostream>
#include <Engine/OpenGL/Renderer.h>
#include <Engine/Window.h>

int main(int c, char** argv) {
//    Application application{1920, 1080, "Jump Point Search and Goal Bounding"};
//    application.run();

    Window window{1920, 1080, "Jump Point Search and Goal Bounding"};
    OpenGL::Renderer renderer{window};

    while(!window.shouldClose())
    {
        renderer.beginFrame();
        // draw quad
        renderer.endFrame();
        window.update();
    }

    return 0;
}
