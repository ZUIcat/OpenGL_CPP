#version 330 core

in vec2 fTexCoord;
in vec4 fColor;

out vec4 FragColor;

uniform sampler2D uTexture;

void main()
{
    FragColor=texture(uTexture,fTexCoord)*fColor;
}
