#version 330 core

out vec4 fColor;

in vec3 color;
in vec2 texCoord;

uniform sampler2D texture0;
uniform sampler2D texture1;

uniform float op = 0.2f;

void main()
{
	//exp1
	//fColor = mix(texture(texture0, texCoord), texture(texture1, vec2(-texCoord.x, texCoord.y)), 0.2f);
	fColor = mix(texture(texture0, texCoord), texture(texture1, vec2(-texCoord.x, texCoord.y)), op);
}