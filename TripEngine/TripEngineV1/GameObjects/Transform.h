#pragma once
#include <glm\glm.hpp>

namespace TripEngine
{
	namespace GameObjects
	{
		struct Transform
		{
		public:
			Transform()
			{
				position = glm::vec3(0);
				rotation = glm::vec3(0);
				scale = glm::vec3(1);
			};

			glm::vec3 position;
			glm::vec3 rotation;
			glm::vec3 scale;

		private:
			inline ~Transform()
			{

			}
		};
	}
}