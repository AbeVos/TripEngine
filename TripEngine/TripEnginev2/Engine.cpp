#include "Engine.h"

using namespace TripEngine;
using namespace Core;

void Engine::Init()
{
	WindowInfo window = WindowInfo();
	ContextInfo context = ContextInfo();
	FramebufferInfo framebufferInfo = FramebufferInfo();

	InitGLUT::Init(window, context, framebufferInfo);
}

void Engine::Run()
{
	InitGLUT::Run();
}