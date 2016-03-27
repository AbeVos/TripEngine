#pragma once
#include "../Rendering/Light.h"
#include <vector>

namespace TripEngine
{
	namespace Managers
	{
		class LightManager
		{
		private:
			static std::vector<Rendering::Light*> lights;

		public:
			static void AddLight(Rendering::Light* light);
			static Rendering::Light* GetLight(int index);
			static int GetNumLights();
		};
	}
}