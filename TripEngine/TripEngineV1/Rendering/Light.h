#pragma once
#include <glm\glm.hpp>

namespace TripEngine
{
	namespace Rendering
	{
		struct Light
		{
		public:
			glm::vec4 position;
			glm::vec3 color;
			float range;
		};
	}
}