#include "Engine.h"

using namespace TripEngine;
using namespace Core;
using namespace Init;

Engine::Engine()
{
	WindowInfo window = WindowInfo();
	ContextInfo context = ContextInfo();
	FramebufferInfo framebufferInfo = FramebufferInfo();

	InitGLUT::Init(window, context, framebufferInfo);

	Init();
}

Engine::~Engine()
{
	delete sceneManager;
	delete modelManager;
	delete shaderManager;
}

void Engine::Init()
{
	sceneManager = new Managers::SceneManager();
	//modelManager = sceneManager

	InitGLUT::SetListener(sceneManager);
}

void Engine::Run()
{
	InitGLUT::Run();
}

Managers::ModelManager* Engine::GetModelManager()
{
	return (Managers::ModelManager*) (sceneManager->GetModelManager());
}

Managers::ShaderManager* Engine::GetShaderManager()
{
	return (Managers::ShaderManager*) (sceneManager->GetShaderManager());
}