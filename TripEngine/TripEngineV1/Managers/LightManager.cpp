#include "LightManager.h"

using namespace TripEngine;
using namespace Managers;

std::vector<Rendering::Light*> LightManager::lights;

void LightManager::AddLight(Rendering::Light* light)
{
	lights.push_back(light);
}

Rendering::Light* LightManager::GetLight(int index)
{
	return lights[index];
}

int LightManager::GetNumLights()
{
	return lights.size();
}