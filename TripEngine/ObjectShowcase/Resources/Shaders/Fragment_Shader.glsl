#version 450 core
layout(location = 0) out vec3 color;

in vec2 uv;
in vec3 normal;

const vec3 lightCol = vec3(1.0, 0.9, 0.4);

uniform float time;
uniform sampler2D textureSampler;
uniform sampler2D lightmapSampler;

uniform mat4 projection_matrix;
uniform mat4 lightMatrix;

void main( void )
{
	vec3 lightDirection = normalize(vec3(1, 3, 2));

	color = dot(lightDirection, normal) * vec3(1, 1, 1) * lightCol;
}