#include "MartrixUtil.h"

int stackTop = 0;
std::vector<glm::mat4 *> MMatrixStack;
glm::mat4 *MMatrix;
glm::mat4 *PMatrix;

glm::mat4 MartrixUtil::GetIdentityM() {
    glm::mat4 mat = glm::mat4(1.0f);
    return mat;
}

void MartrixUtil::Init() { MMatrix = GetIdentityM(); }
void MartrixUtil::Push() {}
void MartrixUtil::Pop() {}
void MartrixUtil::Translate(float x, float y, float z) {}
void MartrixUtil::Rotate(float x, float y, float z, float angle) {}
void MartrixUtil::Scale(float x, float y, float z) {}
