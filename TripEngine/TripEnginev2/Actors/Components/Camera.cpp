#include "Camera.h"

using namespace TripEngine;
using namespace Actors;
using namespace Components;

Camera::Camera(Transform* transform) : Component(transform)
{
	Managers::CameraManager::AddCamera(this);
}

Camera::~Camera()
{

}