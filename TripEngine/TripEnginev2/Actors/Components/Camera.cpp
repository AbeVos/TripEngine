#include "Camera.h"
#include "..\..\Managers\CameraManager.h"

using namespace TripEngine;
using namespace Actors;
using namespace Components;

Camera::Camera(Transform* transform) : Component(transform)
{
	Managers::CameraManager::AddCamera(this);
	VPMatrix = new glm::mat4(1);

	fov = 45.0f;
	nearClipPlane = 0.1f;
	farClipPlane = 1000.0f;

	ambientColor = new glm::vec3(0.1f, 0.2f, 0.05f);
}

Camera::~Camera()
{
	delete VPMatrix;
	delete ambientColor;
}

void Camera::CalculateVPMatrix()
{
	*VPMatrix = glm::perspective(fov, 1.3333f, nearClipPlane, farClipPlane) * glm::inverse(*(transform->GetTransformMatrix()));
}

glm::mat4* Camera::GetVPMatrix()
{
	CalculateVPMatrix();
	return VPMatrix;
}

glm::vec3* Camera::GetAmbientColor()
{
	return ambientColor;
}