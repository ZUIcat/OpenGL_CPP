#include "ShaderUtil.h"

// 创建 Program 并链接 Shader
unsigned int ShaderUtil::CreateProgram(const char *vertShaderSource, const char *fragShaderSource) {
    // 加载顶点着色器
    unsigned int vertShader = CreateShader(GL_VERTEX_SHADER, vertShaderSource);
    if (vertShader == 0) return 0;
    // 加载片元着色器
    unsigned int fragShader = CreateShader(GL_FRAGMENT_SHADER, fragShaderSource);
    if (fragShader == 0) return 0;

    // 创建 Program
    // Creates an empty program object and returns a non-zero value by which it can be referenced
    unsigned int program = glCreateProgram();
    // 若程序创建成功, 则向程序中加入顶点着色器与片元着色器
    if (program != 0) {
        // 向程序中加入顶点着色器
        glAttachShader(program, vertShader);
        // checkGlError("glAttachShader");
        // 向程序中加入片元着色器
        glAttachShader(program, fragShader);
        // checkGlError("glAttachShader");
        // 链接 Program
        glLinkProgram(program);
        // 存放链接成功 Program 数量的数组
        int success;
        // 获取 Program 的链接情况
        glGetProgramiv(program, GL_LINK_STATUS, &success);
        // 若链接失败则报错并删除程序
        if (success != GL_TRUE) {
            char infoLog[512];
            glGetShaderInfoLog(program, 512, nullptr, infoLog);
            std::cout << "[ERROR] Program: Could not link program\n"
                      << infoLog << std::endl;
            glDeleteProgram(program);
            program = 0;
        }
    } else {
        std::cout << "[ERROR] Program: Could not create program" << std::endl;
    }

    // 删除着色器, 它们已经链接到程序中, 不再需要了
    glDeleteShader(vertShader);
    glDeleteShader(fragShader);

    return program;
}

// 加载指定 Shader 的方法
unsigned int ShaderUtil::CreateShader(unsigned int shaderType, const char *shaderSource) {
    // 创建 Shader
    // Creates an empty shader object and returns a non-zero value by which it can be referenced
    unsigned int shader = glCreateShader(shaderType);
    // 若创建成功则加载 Shader
    if (shader != 0) {
        // 加载 Shader 的源代码
        glShaderSource(shader, 1, &shaderSource, nullptr);
        // 编译 Shader
        glCompileShader(shader);
        // 存放编译成功的 Shader 数量
        int success;
        // 获取 Shader 的编译情况
        glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
        // 若 Shader 编译失败显示错误日志, 并删除此 Shader
        if (success != GL_TRUE) {
            char infoLog[512];
            glGetShaderInfoLog(shader, 512, nullptr, infoLog);
            std::cout << "[ERROR] Shader: Could not compile "
                      << (shaderType == 0x8B31 ? "vertex shader" : "frag shader") << "\n"
                      << infoLog << std::endl;
            glDeleteShader(shader);
            shader = 0;
        }
    } else {
        std::cout << "[ERROR] Shader: Could not create "
                  << (shaderType == 0x8B31 ? "vertex shader" : "frag shader")
                  << std::endl;
    }
    return shader;
}

// 从文件中读取出字符串
std::string ShaderUtil::GetStrFromFile(const char *filePath) {
    std::ifstream fileIFStream;
    std::stringstream fileStringStream;
    std::string fileString;

    fileIFStream.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    try {
        fileIFStream.open(filePath);
        fileStringStream << fileIFStream.rdbuf();
        fileIFStream.close();

        fileString = fileStringStream.str();
    } catch (std::ifstream::failure e) {
        std::cout << "[ERROR] File: Could not read file: " << filePath << std::endl;
    }

    return fileString;
}

bool ShaderUtil::CreateShaderProgram(unsigned int &handler, const char *vertShaderPath, const char *fragShaderPath) {
    std::string vertShaderSource = GetStrFromFile(vertShaderPath);
    std::string fragShaderSource = GetStrFromFile(fragShaderPath);
    unsigned int shaderProgram = CreateProgram(vertShaderSource.c_str(), fragShaderSource.c_str());
    if (shaderProgram == 0) {
        std::cout << "[ERROR] ShaderProgram: Could not CreateShaderProgram"<< std::endl;
        return false;
    }
    handler = shaderProgram;
    return true;
}

bool ShaderUtil::GetAttribLocation(unsigned int &handler, unsigned int shaderProgram, const char *name) {
    int index = glGetAttribLocation(shaderProgram, name);
    if (index == -1) {
        std::cout << "[ERROR] Attrib: Could not GetAttribLocation " << name << std::endl;
        return false;
    }
    handler = static_cast<unsigned int>(index);
    return true;
}

bool ShaderUtil::GetUniformLocation(unsigned int &handler, unsigned int shaderProgram, const char *name) {
    int index = glGetUniformLocation(shaderProgram, name);
    if (index == -1) {
        std::cout << "[ERROR] Uniform: Could not GetUniformLocation " << name << std::endl;
        return false;
    }
    handler = static_cast<unsigned int>(index);
    return true;
}
