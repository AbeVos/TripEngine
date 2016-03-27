#version 450 core
layout(location = 0) out vec3 out_color;

in vec2 uv;
in vec3 normal;
in vec3 viewDirection;
in vec3 vertex;

#define MAX_LIGHTS 10
uniform int numLights = 1;
uniform struct Light
{
	vec4 position;
	vec3 color;
	float range;
} lights[MAX_LIGHTS];

uniform sampler2D textureDiffuse;
uniform sampler2D textureNormal;

uniform vec4 light;
uniform vec4 ambient;

vec3 applyLight(Light light)
{
	vec3 lightDirection;
	float attenuation;

	if (light.position.w == 0.0)
	{
		lightDirection = normalize(light.position.xyz);
		attenuation = 1.0;
	}
	else
	{
		lightDirection = normalize(light.position.xyz - vertex);
		attenuation = (light.range - distance(light.position.xyz, vertex)) / light.range;
	}

	vec3 color = texture(textureDiffuse, uv).rgb;

	float diffuse = clamp(dot(normal, lightDirection), 0, 1);
	float specular = clamp(dot(reflect(-viewDirection, normal), lightDirection), 0, 1);
	float rim = (1 - clamp(dot(normal, viewDirection), 0, 1)) * pow(1 - diffuse, 4);

	return max(0, attenuation) * (diffuse * color + 0.6 * pow(specular, 2) + 0.2 * pow(rim, 4)) * light.color;
}

void main( void )
{
	vec3 linearColor = 0.5 * ambient.rgb;

	for(int i = 0; i < numLights; ++i)
	{
		linearColor += applyLight(lights[i]);
	}

	out_color = linearColor;
}