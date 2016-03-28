#pragma once
#include <glm\glm.hpp>
#include "Component.h"

namespace TripEngine
{
	namespace Actors
	{
		namespace Components
		{
			class Transform : public Component
			{
			public:
				Transform();
				Transform(glm::vec3 position, glm::vec3 rotation, glm::vec3 scale);

				virtual ~Transform() override;

				glm::vec3 position;
				glm::vec3 rotation;
				glm::vec3 scale;
			};
		}
	}
}