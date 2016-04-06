#pragma once
#include "Actor.h"
#include "Components\Light.h"

namespace TripEngine
{
	namespace Actors
	{
		class Lamp : public Actor
		{
		public:
			Lamp();
			~Lamp();

		public:
			void SetColor(glm::vec3 color);
			void SetRange(float range);
		};
	}
}