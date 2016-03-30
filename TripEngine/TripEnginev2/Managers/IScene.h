#pragma once
#include "LightManager.h"

namespace TripEngine
{
	namespace Managers
	{
		class IScene
		{
		public:
			IScene();
			virtual ~IScene() = 0;

			virtual void Update() = 0;
			virtual void Draw() = 0;
		};
	}
}