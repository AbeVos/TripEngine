#pragma once
#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>
#include <TripEngineV2\Managers\IScene.h>
#include <TripEngineV2\Actors\Quad.h>
#include <TripEngineV2\Render\Framebuffer.h>
#include "..\Players\Player.h"

using namespace TripEngine;

namespace Scenes
{
	class MainScene : public Managers::IScene
	{
	private:
		Players::Player* player;
		Actors::Quad* quad;

		Rendering::Framebuffer lightFbo;
		Rendering::Framebuffer fbo1;
		Rendering::Framebuffer fbo2;

	public:
		MainScene();
		~MainScene();

	public:
		virtual void Update();
		virtual void Draw();
	};
}