#include "MainScene.h"

using namespace TripEngine;
using namespace Scenes;

MainScene::MainScene()
{
	ambientColor = new glm::vec4(0.1, 0.2, 0.05, 1.0);

	Managers::SceneManager::Init();
	Managers::ShaderManager::CreateProgram("StdMat", "Resources\\Shaders\\Vertex_Shader.glsl", "Resources\\Shaders\\Fragment_Shader.glsl");

	camera = new Actors::CameraObject();
	camera->GetTransform()->position = glm::vec3(0, 1, 2);
	Managers::CameraManager::SetCurrent((Camera*)camera->GetComponent(ct_Camera));

	Actors::Lamp* lamp = new Actors::Lamp();
	lamp->GetTransform()->position = glm::vec3(1, 5, 3);
	lamp->SetColor(glm::vec3(1, 0.8f, 0.5f));

	Actors::Lamp* lamp2 = new Actors::Lamp();
	lamp2->GetTransform()->position = glm::vec3(-3, 1, -2);
	lamp2->SetColor(glm::vec3(0.4f, 0.8f, 0.9f));

	priest = new Actors::Priest();
	priest->GetTransform()->rotation = glm::vec3(0, 2.5f, 0);
}

MainScene::~MainScene()
{
	delete ambientColor;
	delete camera;
	delete priest;
}

void MainScene::Update()
{
	priest->GetTransform()->rotation.y += Managers::TimeManager::delta();
}

void MainScene::Draw()
{
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glClearColor(ambientColor->r, ambientColor->g, ambientColor->b, ambientColor->a);

		Managers::ModelManager::Draw(*ambientColor);
	}
}