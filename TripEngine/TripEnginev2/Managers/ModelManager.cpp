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

void ModelManager::Draw(const GLuint& shadowMap)
{
	for (unsigned int i = 0; i < models.size(); i++)
	{
		models[i]->Draw(shadowMap);
	}
}

void ModelManager::DrawDepth()
{
	for (unsigned int i = 0; i < models.size(); i++)
	{
		models[i]->DrawDepth();
	}
}

void ModelManager::AddModel(Model* model)
{
	models.push_back(model);
}