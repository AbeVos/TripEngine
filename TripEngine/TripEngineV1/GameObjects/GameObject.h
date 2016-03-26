#pragma once
#include "Transform.h"

namespace TripEngine
{
	namespace GameObjects
	{
		class GameObject
		{
		protected:
			Transform* transform;
			glm::mat4 transformMatrix;

		public:
			GameObject();
			~GameObject();

			char* name;

		public:
			virtual void Update();
		};
	}
}