#pragma once
#include <glm\glm.hpp>

namespace TripEngine
{
	namespace Render
	{
		struct Vertex
		{
		public:
			glm::vec3 position;
			glm::vec2 texcoord;
			glm::vec3 normal;

			Vertex(const glm::vec3& position, const glm::vec2& texcoord, const glm::vec3 normal)
			{
				this->position = position;
				this->texcoord = texcoord;
				this->normal = normal;
			}

			Vertex()
			{}
		};
	}
}