#pragma once
#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>

namespace TripEngine
{
	namespace Actors
	{
		namespace Components
		{
			class Transform
			{
			private:
				glm::mat4* transformMatrix;

			public:
				Transform();
				Transform(glm::vec3 position, glm::vec3 rotation, glm::vec3 scale);

				virtual ~Transform();

				glm::vec3 position;
				glm::vec3 rotation;
				glm::vec3 scale;

				glm::mat4* GetTransformMatrix();

			private:
				void CalculateTransformMatrix();
			};
		}
	}
}