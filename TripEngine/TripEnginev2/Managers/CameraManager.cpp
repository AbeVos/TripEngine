#include "CameraManager.h"

using namespace TripEngine;
using namespace Managers;

int CameraManager::currentCameraIndex = 0;
//std::vector<Camera*> CameraManager::cameras;

void CameraManager::AddCamera(Camera* camera)
{
	cameras.push_back(camera);
}

Camera* CameraManager::GetCurrentCamera()
{
	return cameras[currentCameraIndex];
}