#pragma once

#include <glad/glad.h>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class ShaderUtil {
  private:
    ShaderUtil() = default;

  public:
    virtual ~ShaderUtil() = default;

    static unsigned int CreateProgram(const char *vertShaderSource, const char *fragShaderSource);
    static unsigned int CreateShader(unsigned int shaderType, const char *shaderSource);
    static std::string GetStrFromFile(const char *filePath);

    static bool CreateShaderProgram(unsigned int &handler, const char *vertShaderPath, const char *fragShaderPath);
    static bool GetAttribLocation(unsigned int &handler, unsigned int shaderProgram, const char *name);
    static bool GetUniformLocation(unsigned int &handler, unsigned int shaderProgram, const char *name);
};
