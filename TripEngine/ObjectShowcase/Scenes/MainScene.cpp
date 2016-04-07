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

	mushroom = new Actors::Mushroom();
	mushroom->GetTransform()->position = glm::vec3(-1, 0, -2);
	mushroom->GetTransform()->scale = glm::vec3(4, 4, 4);

	fbo1 = Render::Framebuffer();
	fbo1.Create(800, 600);
	fbo2 = Render::Framebuffer();
	fbo2.Create(800, 600);

	quad = new Actors::Quad();
}

MainScene::~MainScene()
{
	delete ambientColor;
	delete camera;
	delete priest;
	delete mushroom;

	fbo1.~Framebuffer();
}

void MainScene::Update()
{
	priest->GetTransform()->rotation.y += Managers::TimeManager::delta();
	mushroom->GetTransform()->scale.y = 4 + 0.2f * glm::sin(5 * Managers::TimeManager::time());
}

void MainScene::Draw()
{
	fbo1.Bind();
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glClearColor(ambientColor->r, ambientColor->g, ambientColor->b, ambientColor->a);

		Managers::ModelManager::Draw(*ambientColor);
	}
	fbo1.Unbind();

	fbo2.Bind();
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		quad->Draw(fbo1.GetColorTexture(), fbo1.GetDepthTexture(), 0, 800, 600);
	}
	fbo2.Unbind();

	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		quad->Draw(fbo2.GetColorTexture(), fbo2.GetDepthTexture(), 1, 800, 600);
	}
}