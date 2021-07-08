#pragma once

#include <iostream>
#include <vector>

#include <glm/glm.hpp>
// #include <glm/ext.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class MartrixUtil {
  private:
    static int stackTop;                          // 栈顶索引
    static std::vector<glm::mat4 *> MMatrixStack; // 保存当前变换矩阵指针的栈
    static glm::mat4 *MMatrix;                    // 当前变换矩阵
    static glm::mat4 *PMatrix;                    // 投影变换矩阵

    MartrixUtil() = default;

    static glm::mat4 GetIdentityM();

  public:
    virtual ~MartrixUtil() = default;

    static void Init();
    static void Push();
    static void Pop();

    static void Translate(float x, float y, float z);
    static void Rotate(float x, float y, float z, float angle);
    static void Scale(float x, float y, float z);

    static void SetOrthoProjection();
    static void SetPerspProjection();

    static glm::mat4 GetMMatrix();
    static glm::mat4 GetMVPMatrix();
    static glm::mat4 GetMPCMatrix();
};
