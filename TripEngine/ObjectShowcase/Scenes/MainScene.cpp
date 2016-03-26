#include "MainScene.h"

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

	ambientColor = new glm::vec4(0.2, 0.4, 0.1, 1.0);
	lightPos = new glm::vec3(0, 3, -3);

	Managers::ShaderManager::CreateProgram("StdMat", "Resources\\Shaders\\Vertex_Shader.glsl", "Resources\\Shaders\\Fragment_Shader.glsl");

	GameObjects::Model* model = new GameObjects::Model("Resources\\Models\\Priest.obj");
	model->SetProgram(Managers::ShaderManager::GetProgram("StdMat"));
	modelManager->AddModel(model);

	GameObjects::Model* suzanne = new GameObjects::Model("Resources\\Models\\Suzanne.obj");
	suzanne->SetProgram(Managers::ShaderManager::GetProgram("StdMat"));
	modelManager->AddModel(suzanne);

	GameObjects::Model* platform = new GameObjects::Model("Resources\\Models\\Platform.obj");
	platform->SetProgram(Managers::ShaderManager::GetProgram("StdMat"));
	modelManager->AddModel(platform);

	suzanne->Translate(glm::vec3(2, 1, 0));
	platform->Translate(glm::vec3(0.0, -0.5, 0.0));

	quad = new GameObjects::Quad();

	fbo1 = Rendering::Framebuffer();
	fbo1.Resize(800, 600);
}

MainScene::~MainScene()
{
	delete modelManager;
}

void MainScene::Update()
{
	*viewMatrix = glm::lookAt(camera.transform->position, glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));

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

		modelManager->Draw(camera.transform->position, *lightPos, *ambientColor);
	}
	fbo1.Unbind();

	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glm::mat4 i_pv_matrix = glm::inverse(*projectionMatrix * glm::translate(*viewMatrix, glm::vec3(0, -camera.transform->position.y, 0)));

		quad->Draw(fbo1.GetColorTexture(), fbo1.GetDepthTexture(), i_pv_matrix);
	}
}