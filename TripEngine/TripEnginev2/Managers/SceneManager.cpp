#include "SceneManager.h"

using namespace TripEngine;
using namespace Managers;

void SceneManager::Init()
{
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
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

void SceneManager::DeleteSceneManager()
{
	std::map<std::string, Managers::IScene*>::iterator i;

	for (i = (&scenes)->begin(); i != (&scenes)->end(); ++i)
	{
		Managers::IScene* scene = i->second;
		delete scene;
	}

	(&scenes)->clear();
}