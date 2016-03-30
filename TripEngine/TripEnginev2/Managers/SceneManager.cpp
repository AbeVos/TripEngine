#include "SceneManager.h"

using namespace TripEngine;
using namespace Managers;

std::string SceneManager::currentScene;
std::map<std::string, IScene*> SceneManager::scenes;

void SceneManager::Init()
{
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

void SceneManager::BeginFrame()
{
	scenes[currentScene]->Update();
}

void SceneManager::DisplayFrame()
{
	scenes[currentScene]->Draw();
}

void SceneManager::EndFrame()
{

}

void SceneManager::Reshape(int width, int height, int prevWidth, int prevHeight)
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