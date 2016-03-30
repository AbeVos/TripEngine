#include "Light.h"

using namespace TripEngine;
using namespace Actors;
using namespace Components;

Light::Light(Transform* transform) : Component(transform)
{
	Managers::LightManager::AddLight(this);
}

Light::~Light()
{

}

glm::mat4 Light::GetLightMatrix()
{
	glm::mat4 viewMatrix = glm::mat4(1);
	glm::mat4 projectionMatrix = glm::mat4(1);

	viewMatrix = *transform->GetTransformMatrix();
	projectionMatrix = glm::ortho(-3.0f, 3.0f, 3.0f, -3.0f, 0.2f, 100.0f);
	
	return glm::inverse(projectionMatrix * viewMatrix);
}