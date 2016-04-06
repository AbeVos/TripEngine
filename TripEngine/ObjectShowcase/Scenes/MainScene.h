#pragma once
#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>
#include <TripEngineV2\Managers\IScene.h>
#include <TripEnginev2\Managers\CameraManager.h>
#include <TripEnginev2\Managers\ShaderManager.h>
#include <TripEnginev2\Actors\CameraObject.h>
#include <TripEngineV2\Actors\Priest.h>

using namespace TripEngine;

namespace Scenes
{
	class MainScene : public Managers::IScene
	{
	private:
		Actors::CameraObject* camera;
		Actors::Priest* priest;

	public:
		MainScene();
		~MainScene();

	public:
		virtual void Update();
		virtual void Draw();
	};
}