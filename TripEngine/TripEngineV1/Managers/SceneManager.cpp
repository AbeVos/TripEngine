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

}

void SceneManager::notifyBeginFrame()
{

}

void SceneManager::notifyDisplayFrame()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.1f, 0.3f, 0.1f, 1.0f);
}

void SceneManager::notifyEndFrame()
{

}

void SceneManager::notifyReshape(int width, int height, int prevWidth, int prevHeight)
{

}