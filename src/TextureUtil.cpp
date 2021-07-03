#include "TextureUtil.h"

#include <glad/glad.h>
#define STB_IMAGE_IMPLEMENTATION
#include "stb/stb_image.h"

std::map<std::string, unsigned int> TextureUtil::texMap; // TODO ??

unsigned int TextureUtil::AddTexture(std::string texName, std::string imagePath) {
    // 纹理 ID
    unsigned int texID;
    // 生成并绑定纹理
    glGenTextures(1, &texID);
    glBindTexture(GL_TEXTURE_2D, texID);
    // 为当前绑定的纹理对象设置环绕和过滤方式
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    // 加载图片并生成纹理
    int width, height, nrChannels;
    unsigned char *data = stbi_load(imagePath.c_str(), &width, &height, &nrChannels, 0);
    if (data) {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        // glGenerateMipmap(GL_TEXTURE_2D);
    } else {
        std::cout << "[ERROR] Texture: Failed to load texture: " << imagePath << std::endl;
    }
    // 释放图片的内存
    stbi_image_free(data);

    // 把名字和生成的纹理ID放到字典里
    texMap.insert(std::make_pair(texName, texID));

    return texID;
}

unsigned int TextureUtil::GetTexture(std::string texName) {
    return texMap.at(texName);
}
