#version 330 core

in vec3 vPos;
in vec4 vColor;
in vec2 vTexCoord;

out vec2 fTexCoord;
out vec4 fColor;

void main()
{
    fTexCoord = vTexCoord;
    fColor = vColor;
    gl_Position=vec4(vPos.x,vPos.y,vPos.z,1.);
}
