#pragma once

#include <iostream>
#include "GLDrawble.h"
#include "ShaderUtil.h"

class Rectangle : public GLDrawble {
  private:
    std::string name;
    unsigned int shaderProgram;
    unsigned int vPosHandle;
    unsigned int vColorHandle;
    unsigned int vTexCoordHandle;
    unsigned int uTextureHandle;
    unsigned int VAO, VBO01, VBO02, VBO03, EBO;
    unsigned int texID01;

  public:
    Rectangle(unsigned int texID01);
    virtual ~Rectangle() override;

    virtual bool InitShader() override;
    virtual bool InitData() override;
    virtual void DrawSelf() override;
    virtual void Delete() override;
};
