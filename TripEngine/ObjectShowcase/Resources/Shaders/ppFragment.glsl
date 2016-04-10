//blur fragment shader
#version 450 core
#define EXTINCTION 0.5
#define NUM_SAMPLES 32
#define INTERLEAVED_GRID_SIZE 8

layout(location = 0) out vec4 out_color;

uniform mat4 VPMatrix;
uniform mat4 lightMatrix;

uniform vec3 cameraPosition;

uniform sampler2D texture_color;
uniform sampler2D texture_depth;
uniform sampler2D shadowMap;

in vec2 uv;

void main()
{
	vec4 color = texture(texture_color, uv);
	float depth = texture(texture_depth, uv).r;
	float shadow = texture(shadowMap, uv).r;

	vec4 worldPosition = inverse(VPMatrix) * vec4(uv.x * 2 - 1, uv.y * 2 - 1, depth * 2 - 1, 1.0);
	worldPosition /= worldPosition.w;
	vec4 rayDirection = vec4(normalize(cameraPosition - worldPosition.xyz), min(length(cameraPosition - worldPosition.xyz), 5));

	float stepSize = rayDirection.w / NUM_SAMPLES;

	vec2 interleavedPos = mod(vec2(800 * uv.x, 600 * uv.y), INTERLEAVED_GRID_SIZE);
	float rayOffset = INTERLEAVED_GRID_SIZE * (interleavedPos.x + interleavedPos.y) * (stepSize / (INTERLEAVED_GRID_SIZE * INTERLEAVED_GRID_SIZE));

	vec3 currentPosition = worldPosition.xyz + stepSize * rayDirection.xyz + rayOffset;
	vec3 result = vec3(0);

	for (int i = 0; i < NUM_SAMPLES; i++)
	{
		vec4 projCoords = lightMatrix * vec4(currentPosition, 1);
		projCoords = 0.5 * (projCoords / projCoords.w + 1);

		float closestDepth = texture(shadowMap, 1 * (projCoords.xy)).r;
		float currentDepth = projCoords.z - 0.001;

		result += stepSize * (currentDepth < closestDepth ? vec3(0.4, 0.4, 0.05) : vec3(0.1, 0.15, 0.0));

		currentPosition += stepSize * rayDirection.xyz;
	}

	result = clamp(result, 0, 1);

	out_color = color * exp(- EXTINCTION) + vec4(result, 1) * exp(- EXTINCTION);
	//out_color = vec4(rayOffset);

	/*vec4 lightSpacePosition = lightMatrix * inverse(VPMatrix) * vec4(uv.x * 2 - 1, uv.y * 2 - 1, depth * 2 - 1, 1.0);

	vec3 projCoords = lightSpacePosition.xyz / lightSpacePosition.w;
	projCoords = 0.5 * (projCoords + 1);

	float closestDepth = texture(shadowMap, 1 * (projCoords.xy)).r;
	float currentDepth = projCoords.z - 0.001;

	float attenuation = currentDepth > closestDepth ? 0.0 : 1.0;

	out_color = vec4(attenuation);*/

	out_color = vec4(pow(out_color.rgb, vec3(exp(-1 / 2.2))), 1);
}