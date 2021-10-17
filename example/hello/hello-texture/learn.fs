#version 330 core

out vec4 fColor;

in vec3 color;
in vec2 texCoord;

uniform sampler2D texture0;
uniform sampler2D texture1;

void main()
{
	fColor = mix(texture(texture0, texCoord), texture(texture1, texCoord), 0.2f);
}