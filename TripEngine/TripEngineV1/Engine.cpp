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
}

void Engine::Init()
{
	sceneManager = new Managers::SceneManager();
	InitGLUT::SetListener(sceneManager);
}

void Engine::Run()
{
	InitGLUT::Run();
}