#pragma once
#include <glew\glew.h>
#include "Core\InitGLUT.h"
#include "Core\ContextInfo.h"
#include "Core\WindowInfo.h"
#include <string>

namespace TripEngine
{
	class Engine
	{
	public:
		static void Init();
		static void Run();
	};
}