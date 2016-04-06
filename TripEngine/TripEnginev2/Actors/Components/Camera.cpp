#include "Camera.h"
#include "..\..\Managers\CameraManager.h"

using namespace TripEngine;
using namespace Actors;
using namespace Components;

Camera::Camera(Transform* transform) : Component(transform)
{
	Managers::CameraManager::AddCamera(this);
	VPMatrix = new glm::mat4(1);

	fov = 60.0f;
	nearClipPlane = 0.2f;
	farClipPlane = 1000.0f;
}

Camera::~Camera()
{

}

void Camera::CalculateVPMatrix()
{
	*VPMatrix = glm::perspective(45.0f, 1.25f, 0.1f, 1000.0f) * glm::inverse(*(transform->GetTransformMatrix()));
}

glm::mat4* Camera::GetVPMatrix()
{
	CalculateVPMatrix();
	return VPMatrix;
}