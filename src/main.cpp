#include <iostream>
#include "Engine/Window.h"

int main(int c, char** argv) {
    Window window{720, 1080, "Pathfinding"};
    while (!window.closed()) {
        // main loop
        window.update();
    }

    return EXIT_SUCCESS;
}
