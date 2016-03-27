#include "MainScene.h"

using namespace TripEngine;
using namespace Scenes;

MainScene::MainScene(Engine* engine)
{
	camera = GameObjects::Camera();
	camera.Translate(glm::vec3(3, 3, -3));

	modelManager = new Managers::ModelManager();

	viewMatrix = new glm::mat4(1);
	projectionMatrix = new glm::mat4(1);

	*viewMatrix = glm::lookAt(camera.transform->position, glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));
	*projectionMatrix = glm::perspective(45.0f, 1.5f, 0.2f, 2000.0f);

	ambientColor = new glm::vec4(0.1, 0.2, 0.05, 1.0);

	lights["main"] = new Rendering::Light();
	lights["main"]->position = glm::vec4(0, 3, -3, 1.0);
	lights["main"]->color = glm::vec3(0.9, 1, 0.3);
	lights["main"]->range = 10.0;
	Managers::LightManager::AddLight(lights["main"]);

	lights["second"] = new Rendering::Light();
	lights["second"]->position = glm::vec4(2, 1, 1, 1.0);
	lights["second"]->color = 0.5f * glm::vec3(0.8, 0.5, 0.1);
	lights["second"]->range = 5.0;
	Managers::LightManager::AddLight(lights["second"]);

	Managers::ShaderManager::CreateProgram("StdMat", "Resources\\Shaders\\Vertex_Shader.glsl", "Resources\\Shaders\\Fragment_Shader.glsl");

	/*GameObjects::Model* model = new GameObjects::Model("Resources\\Models\\Priest.obj");
	model->SetProgram(Managers::ShaderManager::GetProgram("StdMat"));
	model->SetDiffuse(Import::TextureImporter::ImportTexture("Resources\\Textures\\priestGreen.bmp", 512, 512));
	modelManager->AddModel(model);*/

	player = new Players::Player();
	player->SetProgram(Managers::ShaderManager::GetProgram("StdMat"));
	player->SetDiffuse(Import::TextureImporter::ImportTexture("Resources\\Textures\\priestGreen.bmp", 512, 512));
	modelManager->AddModel(player);

	GameObjects::Model* mushroom = new GameObjects::Model("Resources\\Models\\Mushroom.obj");
	mushroom->SetProgram(Managers::ShaderManager::GetProgram("StdMat"));
	mushroom->SetDiffuse(Import::TextureImporter::ImportTexture("Resources\\Textures\\Mushroom_dif.bmp",512, 512));
	modelManager->AddModel(mushroom);

	GameObjects::Model* platform = new GameObjects::Model("Resources\\Models\\Platform.obj");
	platform->SetProgram(Managers::ShaderManager::GetProgram("StdMat"));
	platform->SetDiffuse(Import::TextureImporter::ImportTexture("Resources\\Textures\\Wood_dif.bmp", 512, 512));
	modelManager->AddModel(platform);

	//suzanne->Translate(glm::vec3(2, 1, 0));
	mushroom->transform->scale *= 4;
	mushroom->transform->position += glm::vec3(2, 0, 1);
	platform->Translate(glm::vec3(0.0, -0.5, 0.0));

	quad = new GameObjects::Quad();

	fbo1 = Rendering::Framebuffer();
	fbo1.Resize(800, 600);
	fbo2 = Rendering::Framebuffer();
	fbo2.Resize(800, 600);
}

MainScene::~MainScene()
{
	delete modelManager;

	lights.clear();
}

void MainScene::Update()
{
	camera.transform->position = glm::vec3(4 * glm::cos(0.5 * Time::time()), 2.5 + 2 * glm::sin(0.25 * Time::time()), 4 * glm::sin(0.5 * Time::time()));

	*viewMatrix = glm::lookAt(camera.transform->position, player->transform->position, glm::vec3(0, 1, 0));

	modelManager->SetViewMatrix(viewMatrix);
	modelManager->SetProjectionMatrix(projectionMatrix);
	modelManager->Update();
}

void MainScene::Draw()
{
	fbo1.Bind();
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glClearColor(ambientColor->r, ambientColor->g, ambientColor->b, ambientColor->a);

		modelManager->Draw(camera.transform->position, *ambientColor);
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