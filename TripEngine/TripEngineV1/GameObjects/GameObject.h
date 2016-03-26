#pragma once
#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>
#include "Transform.h"

namespace TripEngine
{
	namespace GameObjects
	{
		class GameObject
		{
		public:
			Transform* transform;

		protected:
			glm::mat4 transformMatrix;

		public:
			GameObject();
			~GameObject();

			char* name;

		public:
			virtual void Update();

			virtual void Translate(const glm::vec3& offset);
		};
	}
}