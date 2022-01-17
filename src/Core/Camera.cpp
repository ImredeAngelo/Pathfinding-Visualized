#include <glm/gtx/transform.hpp>
#include <iostream>
#include "Camera.h"

using namespace glm;

Camera::Camera(int viewportWidth, int viewportHeight) : proj(), view(), pos()
{
    EVENT_LISTENER(onEvent);

    setProjection(viewportWidth, viewportHeight);
//    move(0, 0);

//  WindowResizeEvent::listen(BIND_EVENT(onWindowResize));
}

void Camera::onEvent(Event &event)
{
    BIND_EVENT(event, WindowResizeEvent, onWindowResize);
}

void Camera::onWindowResize(WindowResizeEvent &event)
{
    setProjection(event.getWidth(), event.getHeight());
}

void Camera::move(float x, float y)
{
    pos += vec3(x, y, 0);
    view = translate(pos);
}

void Camera::setProjection(int width, int height)
{
    proj = ortho(0.0f, (float)width, 0.0f, (float)height, -1.0f, 1.0f);
}