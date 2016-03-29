#include "LightManager.h"

using namespace TripEngine;
using namespace Managers;

using namespace Actors::Components;

std::vector<Light*> LightManager::lights;

void LightManager::AddLight(Light* light)
{
	lights.push_back(light);
}

Light* LightManager::GetLight(int index)
{
	return lights[index];
}

int LightManager::GetNumLights()
{
	return lights.size();
}