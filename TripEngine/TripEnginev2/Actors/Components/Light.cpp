#include "Light.h"
#include "..\..\Managers\LightManager.h"

using namespace TripEngine;
using namespace Actors;
using namespace Components;

Light::Light(Transform* transform) : Component(transform)
{
	Managers::LightManager::AddLight(this);
	color = glm::vec3(1);
	type = 0;
}

Light::~Light()
{

}

glm::vec3 Light::GetLightDirection()
{
	if (type == 0)
	{
		glm::vec4 forward = glm::vec4(0, 0, 1, 1);

		glm::mat4 rotation = glm::rotate(glm::mat4(1), transform->rotation.y, glm::vec3(0, 1, 0)) *	//	Second rotation
							 glm::rotate(glm::mat4(1), transform->rotation.x, glm::vec3(1, 0, 0));	//	First rotation

		forward = rotation * forward;

		return glm::normalize(glm::vec3(forward.x, forward.y, forward.z));
	}
	else
	{
		return transform->position;
	}
}

glm::mat4 Light::GetLightMatrix()
{
	glm::mat4 rotation = glm::rotate(glm::mat4(1), transform->rotation.y, glm::vec3(0, 1, 0)) *	//	Second rotation
						 glm::rotate(glm::mat4(1), transform->rotation.x, glm::vec3(1, 0, 0));	//	First rotation

	glm::mat4 position = glm::translate(glm::mat4(1), 10.0f * GetLightDirection());

	glm::mat4 projection = glm::ortho(-5.0f, 5.0f, -5.0f, 5.0f, 0.2f, 50.0f);

	return projection * glm::inverse(position * rotation * glm::mat4(1));
}