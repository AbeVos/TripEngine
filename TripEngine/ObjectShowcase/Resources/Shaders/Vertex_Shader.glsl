#version 450 core
layout(location = 0) in vec3 in_position;
layout(location = 1) in vec2 in_uv;
layout(location = 2) in vec3 in_normal;

uniform mat4 projectionMatrix, viewMatrix, modelMatrix;

uniform vec3 viewPosition;
uniform float time;

out vec2 uv;
out vec3 normal;
out vec3 viewDirection;
out vec3 vertex;

void main( void )
{
	uv = in_uv;
	normal = normalize(mat3(modelMatrix) * in_normal);

	vec4 worldPosition = modelMatrix * vec4(in_position, 1);

	vertex = worldPosition.xyz / worldPosition.w;
	viewDirection = normalize(viewPosition - worldPosition.xyz);
	gl_Position = projectionMatrix * viewMatrix * worldPosition;
}