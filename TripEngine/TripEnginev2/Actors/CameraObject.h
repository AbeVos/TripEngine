#pragma once
#include "Actor.h"
#include "Components\Camera.h"

namespace TripEngine
{
	namespace Actors
	{
		class CameraObject : public Actor
		{
		public:
			CameraObject();
			~CameraObject();
		};
	}
}