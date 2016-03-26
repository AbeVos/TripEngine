#version 450 core
layout(location = 0) out vec3 out_color;

in vec2 uv;
in vec3 normal;
in vec3 viewDirection;

uniform vec3 color = vec3(0.8, 0.3, 0.1);

uniform float time;
uniform sampler2D textureSampler;

uniform vec3 lightPosition;
uniform vec4 ambient;

void main( void )
{
	vec3 lightDirection = normalize(lightPosition);

	float diffuse = 0.5 * ceil(2 * clamp(dot(normal, lightDirection), 0, 1));
	float specular = clamp(dot(reflect(-viewDirection, normal), lightDirection), 0, 1);
	float rim = (1 - clamp(dot(normal, viewDirection), 0, 1)) * pow(1 - diffuse, 4);
	vec3 ambient = 0.5 * ambient.rgb;

	//out_color = (diffuse + 0.8 * step(0.2, pow(specular, 16))) + 0.4 * pow(rim, 4) + ambient;
	out_color = diffuse * color + 0.3 * ceil(2 * pow(specular, 2) - 0.8) * vec3(1) + 0.6 * pow(rim, 4) * vec3(1) + ambient;
}