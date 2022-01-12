#pragma once

#include <glm/glm.hpp>

class Camera
{
public:
    Camera() = default;

    void move(float x, float y);
    void setProjection(int width, int height);

    glm::mat4 getViewMatrix() const { return proj * view; };

private:
    glm::mat4 proj;
    glm::mat4 view;
    glm::vec3 pos;
};
