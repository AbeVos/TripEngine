#pragma once
#include <glm\glm.hpp>
#include "Component.h"

namespace TripEngine
{
	namespace Actors
	{
		namespace Components
		{
			class Camera : public Component
			{
			private:
				glm::mat4* VPMatrix;

			public:
				Camera(Transform* transform);
				~Camera();

			private:
				void CalculateVPMatrix();
				
			public:
				glm::mat4* GetVPMatrix();

				bool perspective;
				float fov;
				float nearClipPlane, farClipPlane;
			};
		}
	}
}