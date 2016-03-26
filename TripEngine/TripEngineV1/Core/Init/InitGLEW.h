#pragma once
#include <glew/glew.h>
#include <freeglut/freeglut.h>
#include <iostream>

namespace TripEngine
{
	namespace Core
	{
		namespace Init
		{
			class InitGLEW
			{
			public:
				static void Init();
			};
		}
	}
}