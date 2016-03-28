#pragma once
#include <freeglut\freeglut.h>

namespace TripEngine
{
	namespace Managers
	{
		class TimeManager
		{
		private:
			static double previousTime;
			static double currentTime;

		public:
			static void Update();
			static const double& time();
			static const double& delta();
		};
	}
}