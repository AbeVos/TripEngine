#pragma once
#include "..\Actors\Components\Camera.h"
#include <vector>

using namespace TripEngine::Actors::Components;

namespace TripEngine
{
	namespace Managers
	{
		class CameraManager
		{
		private:
			static Camera* currentCamera;
			static std::vector<Camera*> cameras;

		public:
			static void AddCamera(Camera* camera);
			static Camera* Current();
			static void SetCurrent(int index);
			static void SetCurrent(Camera* camera);
		};
	}
}