#pragma once
#include "Actor.h"
#include "Components\Model.h"

namespace TripEngine
{
	namespace Actors
	{
		class Platform : public Actor
		{
		public:
			Platform();
			virtual ~Platform();
		};
	}
}