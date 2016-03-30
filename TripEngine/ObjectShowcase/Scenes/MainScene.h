#pragma once
#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>
#include <TripEngineV2\Managers\IScene.h>
#include <TripEngineV2\Actors\Quad.h>
#include <TripEngineV2\Render\Framebuffer.h>

using namespace TripEngine;

namespace Scenes
{
	class MainScene : public Managers::IScene
	{
	public:
		MainScene();
		~MainScene();

	public:
		virtual void Update();
		virtual void Draw();
	};
}