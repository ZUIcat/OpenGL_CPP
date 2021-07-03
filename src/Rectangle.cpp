#include "Rectangle.h"

Rectangle::Rectangle() {
    name = "Rectangle";
    if (!InitShader()) std::cout << "[ERROR] " << name << ": Could not InitShader" << std::endl;
    if (!InitData()) std::cout << "[ERROR] " << name << ": Could not InitData" << std::endl;
}

Rectangle::~Rectangle() {}

bool Rectangle::InitShader() {
    if (!ShaderUtil::CreateShaderProgram(shaderProgram, "./shader/001.vert", "./shader/001.frag")) return false;
    if (!ShaderUtil::GetAttribLocation(vPosHandle, shaderProgram, "vPos")) return false;
    return true;
}

bool Rectangle::InitData() {
    float vertices[] = {
        0.5f,  0.5f,  0.0f, // top right
        0.5f,  -0.5f, 0.0f, // bottom right
        -0.5f, -0.5f, 0.0f, // bottom left
        -0.5f, 0.5f,  0.0f  // top left
    };
    unsigned int indices[] = {
        // note that we start from 0!
        0, 1, 3, // first Triangle
        1, 2, 3  // second Triangle
    };

    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glGenBuffers(1, &EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    // 每个顶点属性从一个 VBO 管理的内存中获得它的数据, 而具体是从哪个 VBO (程序中可以有多个 VBO)
    // 获取则是通过在调用 glVertexAttribPointer 时绑定到 GL_ARRAY_BUFFER 的 VBO 决定的。
    // 由于在调用 glVertexAttribPointer 之前绑定的是先前定义的 VBO 对象, 顶点属性 0 现在会链接到它的顶点数据
    glVertexAttribPointer(vPosHandle, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(vPosHandle);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
    return true;
}

void Rectangle::DrawSelf() {
    glUseProgram(shaderProgram);
    glBindVertexArray(VAO);
    // glDrawArrays(GL_TRIANGLES, 0, 6);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    // glBindVertexArray(0); // no need to unbind it every time
}

void Rectangle::Delete() {
    // optional: de-allocate all resources once they've outlived their purpose:
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
    glDeleteProgram(shaderProgram);
}
