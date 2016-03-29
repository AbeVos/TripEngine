#pragma once
#include <TripEngineV2\Engine.h>
#include <TripEnginev2\Managers\SceneManager.h>
#include <TripEngineV2\Managers\ModelManager.h>
#include <TripEngineV2\Actors\Actor.h>
#include "Scenes\MainScene.h"
#include <string>

using namespace TripEngine;

int main(int argc, char **argv)
{
	Scenes::MainScene* scene = new Scenes::MainScene();

	Managers::SceneManager::CreateScene("mainScene", scene);
	Managers::SceneManager::SetCurrentScene("mainScene");

	Engine::Run();

	return 0;
}