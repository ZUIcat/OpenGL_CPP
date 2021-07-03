#pragma once

#include <iostream>
#include "RenderWindow.h"
#include "Rectangle.h"

class MyRenderWindow : public RenderWindow {
  private:
    Rectangle* rectangle;

    virtual void ProcessInput();
    static void FramebufferSizeCallback(GLFWwindow *glfwWindow, int width, int height);

  protected:
    virtual void OnWindowCreated() override;
    virtual void OnDrawFrame() override;
    virtual void OnWindowDestroy() override;

  public:
    using RenderWindow::RenderWindow;
    // MyRenderWindow();
    virtual ~MyRenderWindow() override;

};
