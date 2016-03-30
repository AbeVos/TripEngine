#pragma once
#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>
#include "Components\ComponentType.h"
#include "Components\Transform.h"
#include "Components\Component.h"
#include <map>
#include <string>

using namespace TripEngine;
using namespace Actors;
using namespace Components;

namespace TripEngine
{
	namespace Actors
	{
		class Actor
		{
		protected:
			char* name;

			Transform* transform;
			std::map<ComponentType, Component*> components;

		public:
			Actor();
			virtual ~Actor();

		public:
			virtual void Update();

			virtual Transform* GetTransform();
			virtual void AddComponent(ComponentType type, Component* component);
			virtual Component* GetComponent(ComponentType type);
		};
	}
}