#pragma once
#include <freeglut\freeglut.h>

namespace TripEngine
{
	class Time
	{
	private:
		static float previousTime;
		static float currentTime;

	public:
		static void Update();
		static const float& time();
		static const float& delta();
	};
}