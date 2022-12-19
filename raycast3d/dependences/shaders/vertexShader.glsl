#version 330 core
layout (location = 0) in vec4 aPos;

uniform vec4 translation;

void main()
{
    gl_Position = aPos+translation;
};