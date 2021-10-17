#version 330 core

in vec3 color;
in vec3 pos;
out vec4 fColor;

void main()
{
	fColor = vec4(pos, 1.0f);
}