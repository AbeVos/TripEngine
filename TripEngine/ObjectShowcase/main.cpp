#pragma once
#include <TripEngineV2\Engine.h>
#include <TripEngineV2\Managers\ModelManager.h>
#include <TripEngineV2\Actors\Actor.h>
#include "Scenes\MainScene.h"
#include <string>

using namespace TripEngine;

int main(int argc, char **argv)
{
	Scenes::MainScene* scene = new Scenes::MainScene(engine);

	engine->CreateScene("mainScene", scene);
	engine->SetCurrentScene("mainScene");

	engine->Run();

	return 0;
}