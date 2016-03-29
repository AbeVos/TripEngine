#pragma once
#include "Component.h"
#include "..\..\Managers\CameraManager.h"

namespace TripEngine
{
	namespace Actors
	{
		namespace Components
		{
			class Camera : public Component
			{
			public:
				Camera(Transform* transform);
				~Camera();

				bool perspective;
				float fov;
				float nearClipPlane, farClipPlane;
			};
		}
	}
}