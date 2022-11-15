#include "Texture.h"

Texture::Texture(std::string img, GLenum texType, GLenum slot, GLenum format, GLenum pixelType) {
    type = texType;
    int numColCh;
    stbi_set_flip_vertically_on_load(true);
    unsigned char* bytes = stbi_load(("textures/"+img).c_str(), &width, &height,
                                    &numColCh, 0);
    if (!bytes){
        std::cout << "Error loading image on path: " << ("textures/"+img).c_str();
        return;
    }
    glGenTextures(1, &ID);
    glActiveTexture(slot);
    glBindTexture(texType, ID);

    glad_glTexParameteri(texType, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glad_glTexParameteri(texType, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    glad_glTexParameteri(texType, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glad_glTexParameteri(texType, GL_TEXTURE_WRAP_T, GL_REPEAT);

    glTexImage2D(texType, 0, GL_RGBA, width, height, 0, format, pixelType, bytes);
    glGenerateMipmap(texType);

    stbi_image_free(bytes);
    glBindTexture(texType, 0);
    glActiveTexture(GL_TEXTURE0);
}

void Texture::texUnit(Shader shader, const char *uniform, GLuint unit) {
    GLuint tex0Uni = glGetUniformLocation(shader.ID, uniform);
    shader.Activate();
    glUniform1i(tex0Uni, unit);
}

void Texture::Bind() {
    glBindTexture(type, ID);
}

void Texture::Unbind() {
    glBindTexture(type, 0);
}

void Texture::Delete() {
    glDeleteTextures(1, &ID);
}