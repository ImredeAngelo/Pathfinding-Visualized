#include <iostream>
#include <Engine/Application.h>

int main(int c, char** argv) {
    Application application{1920, 1080, "Jump Point Search and Goal Bounding"};
    application.run();
    return 0;
}
