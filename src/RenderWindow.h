#pragma once

#include <iostream>
#include <glad/glad.h>
// GLFW (include after glad)
#include <GLFW/glfw3.h>

class RenderWindow {
  protected:
    const char *title;
    const int width;
    const int height;
    GLFWwindow *glfwWindow;

    virtual void OnWindowCreated() = 0;
    virtual void OnDrawFrame() = 0;
    virtual void OnWindowDestroy() = 0;

  public:
    RenderWindow(const char *title, unsigned int width, unsigned int height);
    virtual ~RenderWindow();

    virtual GLFWwindow *InitWindow();
    virtual void StartDraw();
};
