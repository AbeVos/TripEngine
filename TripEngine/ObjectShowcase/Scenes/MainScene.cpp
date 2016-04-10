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

	mushrooms = std::vector<Actors::Mushroom*>();

	Actors::Mushroom* mush1 = new Actors::Mushroom();
	mush1->GetTransform()->position = glm::vec3(1.6f, 0, 1.8f);
	mush1->GetTransform()->rotation.y = 2.5f;
	mush1->GetTransform()->scale = glm::vec3(3.5f, 3.0f, 3.5f);
	mushrooms.push_back(mush1);

	Actors::Mushroom* mush2 = new Actors::Mushroom();
	mush2->GetTransform()->position = glm::vec3(-1.5f, 0, 1.4f);
	mush2->GetTransform()->rotation.y = -3.0f;
	mush2->GetTransform()->scale = glm::vec3(3.0f, 5.0f, 3.0f);
	mushrooms.push_back(mush2);

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

	priest->GetTransform()->position = glm::vec3(glm::cos(-time), 0, glm::sin(-time));
	priest->GetTransform()->rotation.y = time;

	//camera->GetTransform()->position.z = 5 + glm::sin(time);
	camera->GetTransform()->position = priest->GetTransform()->position + glm::vec3(3 * glm::cos(0.5f * time), 1, 3 * glm::sin(0.5f * time));
	camera->GetTransform()->rotation.y = -0.5 * (time - 3.1415f);

	mushroom->GetTransform()->scale.y = 4 + 0.2f * glm::sin(5 * time);

	for (int i = 0; i < mushrooms.size(); i++)
	{
		mushrooms[i]->GetTransform()->scale.y = 4 + 0.2f * glm::sin(5 * time + i + 1);
	}
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
		quad->Draw(fbo2.GetColorTexture(), fbo2.GetDepthTexture(), fbo1.GetDepthTexture());
	}
}