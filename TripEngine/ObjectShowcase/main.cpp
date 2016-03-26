#pragma once
#include <TripEngineV1\Engine.h>
#include <TripEngineV1\Managers\ModelManager.h>
#include <TripEngineV1\GameObjects\Model.h>

using namespace TripEngine;

int main(int argc, char **argv)
{
	Engine* engine = new Engine();
	Managers::ShaderManager* shaderMgr = engine->GetShaderManager();
	Managers::ModelManager* modelMgr = engine->GetModelManager();

	shaderMgr->CreateProgram("StdMat", "Resources\\Shaders\\Vertex_Shader.glsl", "Resources\\Shaders\\Fragment_Shader.glsl");

	GameObjects::Model* model = new GameObjects::Model("Resources\\Models\\Priest.obj");
	model->SetProgram(shaderMgr->GetProgram("StdMat"));
	modelMgr->AddModel(model);

	GameObjects::Model* suzanne = new GameObjects::Model("Resources\\Models\\Suzanne.obj");
	suzanne->SetProgram(shaderMgr->GetProgram("StdMat"));
	modelMgr->AddModel(suzanne);

	engine->Run();

	return 0;
}