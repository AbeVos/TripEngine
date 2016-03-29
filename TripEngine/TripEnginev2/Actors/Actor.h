#pragma once
#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>
#include "Components\Component.h"
#include "Components\ComponentType.h"
#include "Components\Transform.h"
#include <map>
#include <string>

using namespace TripEngine::Actors::Components;

namespace TripEngine
{
	namespace Actors
	{
		class Actor
		{
		private:
			char* name;

			Transform* transform;
			std::map<ComponentType, Component*> components;

		public:
			Actor();
			virtual ~Actor();

		public:
			virtual void Update();

			virtual void AddComponent();
			virtual const Component& GetComponent(ComponentType type);
		};
	}
}