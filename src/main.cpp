#include "Engine/Window.h"
#include <iostream>

int main(int c, char** argv) {
    Window window{1920, 1080, "Pathfinding"};
    while (!window.closed()) {
        window.update();
    }

    return EXIT_SUCCESS;
}
