//blur fragment shader
#version 450 core

layout(location = 0) out vec4 out_color;

const float weights[6] = float[] (0.141836, 0.13424, 0.113806, 0.086425, 0.05879, 0.035822);
//const float weights[6] = float[] (0.035822, 0.05879, 0.086425, 0.113806, 0.13424, 0.141836);

uniform sampler2D texture_color;
uniform sampler2D texture_depth;

uniform int pass = 0;
uniform int width, height;

in vec2 uv;

void main()
{
	vec4 color = texture(texture_color, uv);
	float depth = texture(texture_depth, uv).r;

	out_color = color;

	out_color = vec4(pow(out_color.rgb, vec3(exp(-1 / 2.2))), 1);
}