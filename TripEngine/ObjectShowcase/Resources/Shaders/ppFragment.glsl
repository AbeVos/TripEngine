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

float intensity(float treshold, vec2 uv)
{
	vec3 color = texture(texture_color, uv).rgb;
	//return step(treshold, (color.r + color.g + color.b) / 3.0);
	return 2 * pow((color.r + color.g + color.b) / 3.0, 16);
}

void main()
{
	vec4 color = texture(texture_color, uv);
	
	if (pass == 0)
	{
		float bloom = intensity(0.8, uv) * weights[0];
		float offset = 3.0 / width;

		for (int i = 1; i < 6; i++)
		{
			bloom += (intensity(0.8, uv + vec2(i * offset, 0)) +
				intensity(0.8, uv + vec2(-i * offset, 0))) * weights[i];
		}

		out_color = vec4(color.rgb, bloom);
	}
	else
	{
		float bloom = color.a * weights[0];
		float offset = 3.0 / height;

		for (int i = 1; i < 6; i++)
		{
			bloom += (texture(texture_color, uv + vec2(0, i * offset)).a +
				texture(texture_color, uv + vec2(0, -i * offset)).a) * weights[i];
		}

		out_color = vec4((1.5 - color.rgb) * bloom + color.rgb, 1);
	}
}