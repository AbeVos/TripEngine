#pragma once
#include "..\Actors\Components\Light.h"
#include <vector>

using namespace TripEngine::Actors::Components;

namespace TripEngine
{
	namespace Managers
	{
		class LightManager
		{
		private:
			static std::vector<Light*> lights;

		public:
			static void AddLight(Light* light);
			static Light* GetLight(int index);
			static int GetNumLights();
		};
	}
}