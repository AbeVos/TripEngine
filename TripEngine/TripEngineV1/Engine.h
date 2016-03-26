#pragma once
#include <glew\glew.h>
#include "Core\Init\InitGLUT.h"
#include "Core\Init\IListener.h"
#include "Managers\SceneManager.h"
#include "Managers\ModelManager.h"
#include "Managers\ShaderManager.h"
#include "Managers\IScene.h"
#include <string>

namespace TripEngine
{
	class Engine
	{
	private:
		Managers::SceneManager* sceneManager;

	public:
		Engine();
		~Engine();

	private:
		void Init();

	public:
		void Run();

		void CreateScene(const std::string& name, Managers::IScene* scene);
		void SetCurrentScene(const std::string& name);
	};
}