#include "CameraManager.h"

using namespace TripEngine;
using namespace Managers;

Camera* CameraManager::currentCamera;
std::vector<Camera*> CameraManager::cameras;

void CameraManager::AddCamera(Camera* camera)
{
	cameras.push_back(camera);
}

Camera* CameraManager::Current()
{
	return currentCamera;
}

void CameraManager::SetCurrent(int index)
{
	currentCamera = cameras[index];
}

void CameraManager::SetCurrent(Camera* camera)
{
	currentCamera = camera;
}