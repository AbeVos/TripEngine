#pragma once
#include <glew\glew.h>
#include "Core\Init\InitGLUT.h"
#include "Core\Init\IListener.h"
#include "Managers\SceneManager.h"

namespace TripEngine
{
	class Engine
	{
	private:
		Core::IListener* sceneManager;

	public:
		Engine();
		~Engine();

	private:
		void Init();

	public:
		void Run();
	};
}