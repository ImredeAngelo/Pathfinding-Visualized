#include "Engine/Window.h"
#include <iostream>

int main(int c, char** argv) {
    Window window{1920, 1080, "Jump Point Search and Goal Bounding"};
    while (!window.closed()) {
        // get input from command line

        window.update();
    }

    return EXIT_SUCCESS;
}
