#pragma once

#include <iostream>
#include "GLDrawble.h"
#include "ShaderUtil.h"

class Rectangle : public GLDrawble {
  private:
    std::string name;
    unsigned int shaderProgram;
    unsigned int vPosHandle;
    unsigned int VBO, VAO, EBO;

  public:
    Rectangle();
    virtual ~Rectangle() override;

    virtual bool InitShader() override;
    virtual bool InitData() override;
    virtual void DrawSelf() override;
    virtual void Delete() override;
};
