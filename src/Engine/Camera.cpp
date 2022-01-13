#include <glm/gtx/transform.hpp>
#include "Camera.h"

using namespace glm;

// TODO: Camera bound to scene
void Camera::move(float x, float y)
{
    pos += vec3(x, y, 0);
    view = translate(pos);
}

void Camera::setProjection(int width, int height)
{
    proj = ortho(0.0f, (float)width, 0.0f, (float)height, -1.0f, 1.0f);
}
