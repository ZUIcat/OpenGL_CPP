#include "MyRenderWindow.h"
#include "TextureUtil.h"

MyRenderWindow::~MyRenderWindow() {}

void MyRenderWindow::OnWindowCreated() {
    glfwSetFramebufferSizeCallback(glfwWindow, FramebufferSizeCallback);
    glEnable(GL_CULL_FACE);
    TextureUtil::AddTexture("tex003", "./res/tex003.png");
    rectangle = new Rectangle(TextureUtil::GetTexture("tex003"));
}

void MyRenderWindow::OnDrawFrame() {
    ProcessInput();
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    rectangle->DrawSelf();
}

void MyRenderWindow::OnWindowDestroy() {
    rectangle->Delete();
    delete(rectangle);
    glfwTerminate();
}

void MyRenderWindow::ProcessInput() {
    if (glfwGetKey(glfwWindow, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(glfwWindow, true);
    }
}

void MyRenderWindow::FramebufferSizeCallback(GLFWwindow *glfwWindow, int width, int height) {
    glViewport(0, 0, width, height);
}
