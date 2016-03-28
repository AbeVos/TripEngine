#pragma once
#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>

namespace TripEngine
{
	namespace Rendering
	{
		class Light
		{
		public:
			glm::vec4 position;
			glm::vec3 color;
			float range;

			glm::mat4 GetLightMatrix();
		};
	}
}