#version 450 core
layout(location = 0) in vec3 in_position;
layout(location = 1) in vec2 in_uv;
layout(location = 2) in vec3 in_normal;

uniform mat4 projection_matrix, view_matrix, model_matrix;
uniform vec3 viewPosition;
uniform float time;

out vec2 uv;
out vec3 normal;

void main( void )
{
	uv = in_uv;
	//normal = (model_matrix * vec4(normalize(in_normal), 0)).xyz;
	//gl_Position = projection_matrix * view_matrix * model_matrix * vec4(in_position, 1.0);
	normal = in_normal;
	gl_Position = vec4(in_position, 1);
}