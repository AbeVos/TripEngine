#include "SceneManager.h"

using namespace TripEngine;
using namespace Managers;

SceneManager::SceneManager()
{
	glEnable(GL_DEPTH_TEST);

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

SceneManager::~SceneManager()
{
	std::map<std::string, Managers::IScene*>::iterator i;

	for (i = (&scenes)->begin(); i != (&scenes)->end(); ++i)
	{
		Managers::IScene* scene = i->second;
		delete scene;
	}

	(&scenes)->clear();
}

void SceneManager::notifyBeginFrame()
{
	scenes[currentScene]->Update();
}

void SceneManager::notifyDisplayFrame()
{
	scenes[currentScene]->Draw();
}

void SceneManager::notifyEndFrame()
{

}

void SceneManager::notifyReshape(int width, int height, int prevWidth, int prevHeight)
{

}

void SceneManager::CreateScene(const std::string& name, Managers::IScene* scene)
{
	scenes[name] = scene;
}

void SceneManager::SetCurrentScene(const std::string& name)
{
	currentScene = name;
}

const Managers::IScene* SceneManager::GetCurrentScene()
{
	return scenes[currentScene];
}