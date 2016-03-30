#include "Camera.h"

using namespace TripEngine;
using namespace Actors;
using namespace Components;

Camera::Camera(Transform* transform) : Component(transform)
{
	Managers::CameraManager::AddCamera(this);
	VPMatrix = new glm::mat4(1);
}

Camera::~Camera()
{

}

void Camera::CalculateVPMatrix()
{
	*VPMatrix = glm::perspective(fov, 1.5f, nearClipPlane, farClipPlane) *	//	Projection matrix
		glm::inverse(*transform->GetTransformMatrix());						//	View matrix
}

glm::mat4* Camera::GetVPMatrix()
{
	CalculateVPMatrix();
	return VPMatrix;
}