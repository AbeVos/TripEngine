#include "MainScene.h"

using namespace TripEngine;
using namespace Scenes;

MainScene::MainScene()
{
	Managers::SceneManager::Init();
	Managers::ShaderManager::CreateProgram("StdMat", "Resources\\Shaders\\Vertex_Shader.glsl", "Resources\\Shaders\\Fragment_Shader.glsl");

	camera = new Actors::CameraObject();
	camera->GetTransform()->position = glm::vec3(0, 1, 2);
	camera->GetTransform()->rotation.x = -0.2f;
	Managers::CameraManager::SetCurrent((Camera*)camera->GetComponent(ct_Camera));

	Actors::Lamp* lamp = new Actors::Lamp();
	lamp->GetTransform()->rotation = glm::vec3(-0.8f, 1.0f, 0);
	lamp->SetColor(glm::vec3(1, 0.8f, 0.5f));
	lamp->SetType(0);

	Actors::Lamp* lamp2 = new Actors::Lamp();
	lamp2->GetTransform()->position = glm::vec3(-3, 1, -2);
	lamp2->SetColor(glm::vec3(0.4f, 0.8f, 0.9f));
	lamp2->SetType(1);

	priest = new Actors::Priest();
	priest->GetTransform()->rotation = glm::vec3(0, 2.5f, 0);

	mushroom = new Actors::Mushroom();
	mushroom->GetTransform()->position = glm::vec3(1, 0, -2);
	mushroom->GetTransform()->scale = glm::vec3(4, 4, 4);

	platform = new Actors::Platform();

	fbo1 = Render::Framebuffer();
	fbo1.Create(800, 600);
	fbo2 = Render::Framebuffer();
	fbo2.Create(800, 600);

	quad = new Actors::Quad();
}

MainScene::~MainScene()
{
	delete camera;
	delete priest;
	delete mushroom;

	fbo1.~Framebuffer();
}

void MainScene::Update()
{
	float time = Managers::TimeManager::time();

	camera->GetTransform()->position = glm::vec3(2 * glm::cos(0.5f * time), 1, 2 * glm::sin(0.5f * time));
	camera->GetTransform()->rotation.y = -0.5 * (time - 3.1415f);
	priest->GetTransform()->rotation.y += Managers::TimeManager::delta();
	mushroom->GetTransform()->scale.y = 4 + 0.2f * glm::sin(5 * Managers::TimeManager::time());
}

void MainScene::Draw()
{
	glm::vec3* ambient = Managers::CameraManager::Current()->GetAmbientColor();

	fbo1.Bind();	//	TODO: Make a shadowbuffer for this bit.
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//glCullFace(GL_FRONT);
		Managers::ModelManager::DrawDepth();
		glCullFace(GL_BACK);
	}
	fbo1.Unbind();

	fbo2.Bind();
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glClearColor(ambient->r, ambient->g, ambient->b, 1);

		Managers::ModelManager::Draw(fbo1.GetDepthTexture());
	}
	fbo2.Unbind();

	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		quad->Draw(fbo2.GetColorTexture(), fbo2.GetDepthTexture(), 0, 800, 600);
	}
}