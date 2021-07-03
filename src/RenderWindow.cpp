#include "RenderWindow.h"

RenderWindow::RenderWindow(char *title, unsigned int width, unsigned int height)
    : title(title), width(width), height(height) {
}

RenderWindow::~RenderWindow() {} // TODO

GLFWwindow *RenderWindow::InitWindow() {
    // glfw: initialize and configure
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    // glfw: window creation
    glfwWindow = glfwCreateWindow(width, height, title, nullptr, nullptr);
    if (glfwWindow == nullptr) {
        std::cout << "[ERROR] RenderWindow: Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return nullptr;
    }

    glfwMakeContextCurrent(glfwWindow);
    // glfwSetFramebufferSizeCallback(window, FramebufferSizeCallback); // TODO

    // glad: load all OpenGL function pointers
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "[ERROR] RenderWindow: Failed to initialize GLAD" << std::endl;
        return nullptr;
    }

    OnWindowCreated();
    return glfwWindow;
}

void RenderWindow::StartDraw() {
    // render loop
    while (!glfwWindowShouldClose(glfwWindow)) {
        // render
        OnDrawFrame();
        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        glfwSwapBuffers(glfwWindow); // TODO
        glfwPollEvents(); // TODO
    }
    OnWindowDestroy(); // TODO 缺个手动点击关闭按钮的回调方法
}
