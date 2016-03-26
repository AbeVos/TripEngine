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
		models[i]->Update();
	}
}

void ModelManager::Draw()
{
	for (unsigned int i = 0; i < models.size(); i++)
	{
		models[i]->Draw();
	}
}

void ModelManager::AddModel(GameObjects::Model* model)
{
	models.push_back(model);
}