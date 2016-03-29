#pragma once
#include <glew\glew.h>
#include "Core\InitGLUT.h"
#include "Core\IListener.h"
#include "Core\ContextInfo.h"
#include "Core\WindowInfo.h"
#include "Core\FramebufferInfo.h"
#include "Managers\SceneManager.h"
#include "Managers\ShaderManager.h"
#include "Managers\IScene.h"
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