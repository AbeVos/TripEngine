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