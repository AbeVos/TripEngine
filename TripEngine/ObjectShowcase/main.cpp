#pragma once
#include <TripEngineV1\Engine.h>
#include <TripEngineV1\Managers\ModelManager.h>
#include <TripEngineV1\GameObjects\Model.h>
#include <TripEngineV1\Managers\IScene.h>
#include "Scenes\MainScene.h"
#include <string>

using namespace TripEngine;

int main(int argc, char **argv)
{
	Engine* engine = new Engine();

	Scenes::MainScene* scene = new Scenes::MainScene(engine);

	engine->CreateScene("mainScene", scene);
	engine->SetCurrentScene("mainScene");

	//Managers::ShaderManager* shaderMgr = engine->GetShaderManager();

	//shaderMgr->CreateProgram("StdMat", "Resources\\Shaders\\Vertex_Shader.glsl", "Resources\\Shaders\\Fragment_Shader.glsl");

	engine->Run();

	return 0;
}