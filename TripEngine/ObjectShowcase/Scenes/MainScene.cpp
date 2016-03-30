#include "MainScene.h"
#include <TripEnginev2\Import\TextureImporter.h>

using namespace TripEngine;
using namespace Scenes;

MainScene::MainScene()
{
	ambientColor = new glm::vec4(0.1, 0.2, 0.05, 1.0);

	Managers::ShaderManager::CreateProgram("StdMat", "Resources\\Shaders\\Vertex_Shader.glsl", "Resources\\Shaders\\Fragment_Shader.glsl");

	camera = new Actors::CameraObject();
	camera->GetTransform()->position = glm::vec3(0, 0, 2);
	Managers::CameraManager::SetCurrent((Camera*)camera->GetComponent(ct_Camera));
	cube = new Actors::Cube();
	cube->GetTransform()->position = glm::vec3(0, 2, 0);
}

MainScene::~MainScene()
{
	delete ambientColor;
}

void MainScene::Update()
{
	Managers::ModelManager::Update();
}

void MainScene::Draw()
{
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glClearColor(ambientColor->r, ambientColor->g, ambientColor->b, ambientColor->a);

		Managers::ModelManager::Draw(*ambientColor);
	}
}