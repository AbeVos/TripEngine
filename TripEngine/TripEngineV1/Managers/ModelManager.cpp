#include "ModelManager.h"

using namespace TripEngine;
using namespace Managers;

ModelManager::ModelManager()
{
	models = std::vector<GameObjects::Model*>();
}

ModelManager::~ModelManager()
{
	for (unsigned int i = 0; i < models.size(); i++)
	{
		delete models[i];
	}

	models.clear();
}

void ModelManager::Update()
{
	for (unsigned int i = 0; i < models.size(); i++)
	{
		models[i]->SetViewMatrix(viewMatrix);
		models[i]->SetProjectionMatrix(projectionMatrix);
		models[i]->Update();
	}
}

void ModelManager::Draw(const glm::vec3& viewPos, const glm::vec3& lightPos, const glm::vec4& ambientColor)
{
	for (unsigned int i = 0; i < models.size(); i++)
	{
		models[i]->Draw(viewPos, lightPos, ambientColor);
	}
}

void ModelManager::AddModel(GameObjects::Model* model)
{
	models.push_back(model);
}void ModelManager::SetViewMatrix(glm::mat4* matrix)
{
	viewMatrix = matrix;
}

void ModelManager::SetProjectionMatrix(glm::mat4* matrix)
{
	projectionMatrix = matrix;
}