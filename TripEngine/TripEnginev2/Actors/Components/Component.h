#pragma once
#include "Transform.h"

namespace TripEngine
{
	namespace Actors
	{
		namespace Components
		{
			class Component
			{
			protected:
				Transform* transform;

			public:
				Component(Transform* transform);
				virtual ~Component();

				virtual Transform* GetTransform();
			};
		}
	}
}