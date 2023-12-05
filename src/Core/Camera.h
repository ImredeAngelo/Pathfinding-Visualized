#pragma once

#include <glm/glm.hpp>
#include <Events/WindowEvent.h>

class Camera
{
public:
    Camera(int viewportWidth, int viewportHeight);

    void onEvent(Event&);
    void onWindowResize(WindowResizeEvent&);
// void onScroll(const MouseScrollEvent&);
// void onKeyDown(const KeyPressEvent&);
// void onKeyUp(const KeyReleaseEvent&);

    glm::mat4 getViewMatrix() const { return proj; };

    void move(float x, float y);
private:
    void setProjection(int width, int height);

private:
    glm::mat4 proj;
    glm::mat4 view;
    glm::vec3 pos;
};
