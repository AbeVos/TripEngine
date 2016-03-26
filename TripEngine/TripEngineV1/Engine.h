#pragma once
#include <glew\glew.h>
#include "Core\Init\InitGLUT.h"
#include "Core\Init\IListener.h"
#include "Managers\SceneManager.h"
#include "Managers\ModelManager.h"
#include "Managers\ShaderManager.h"

namespace TripEngine
{
	class Engine
	{
	private:
		Managers::SceneManager* sceneManager;
		Managers::ModelManager* modelManager;
		Managers::ShaderManager* shaderManager;

	public:
		Engine();
		~Engine();

	private:
		void Init();

	public:
		void Run();

		Managers::ModelManager* GetModelManager();
		Managers::ShaderManager* GetShaderManager();
	};
}