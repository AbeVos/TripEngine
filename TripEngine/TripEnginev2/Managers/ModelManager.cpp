#include "ModelManager.h"

using namespace TripEngine;
using namespace Managers;

std::vector<Model*> ModelManager::models = std::vector<Model*>();

void ModelManager::Update()
{
	for (unsigned int i = 0; i < models.size(); i++)
	{
	}
}

void ModelManager::Draw(const glm::vec4& ambientColor)
{
	for (unsigned int i = 0; i < models.size(); i++)
	{
		models[i]->Draw(ambientColor);
	}
}

void ModelManager::AddModel(Model* model)
{
	models.push_back(model);
}