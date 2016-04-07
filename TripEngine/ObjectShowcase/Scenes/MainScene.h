#pragma once
#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>
#include <TripEngineV2\Managers\IScene.h>
#include <TripEnginev2\Managers\SceneManager.h>
#include <TripEnginev2\Managers\CameraManager.h>
#include <TripEnginev2\Managers\LightManager.h>
#include <TripEnginev2\Managers\ShaderManager.h>
#include <TripEnginev2\Managers\TimeManager.h>
#include <TripEnginev2\Render\Framebuffer.h>
#include <TripEnginev2\Actors\CameraObject.h>
#include <TripEnginev2\Actors\Lamp.h>
#include <TripEngineV2\Actors\Priest.h>
#include <TripEnginev2\Actors\Mushroom.h>
#include <TripEnginev2\Actors\Quad.h>

using namespace TripEngine;

namespace Scenes
{
	class MainScene : public Managers::IScene
	{
	private:
		Actors::CameraObject* camera;
		Actors::Priest* priest;
		Actors::Mushroom* mushroom;

		Render::Framebuffer fbo1;
		Render::Framebuffer fbo2;

		Actors::Quad* quad;

	public:
		MainScene();
		~MainScene();

	public:
		virtual void Update();
		virtual void Draw();
	};
}