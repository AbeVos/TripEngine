#include "Light.h"

using namespace TripEngine;
using namespace Rendering;

glm::mat4 Light::GetLightMatrix()
{
	glm::mat4 viewMatrix = glm::mat4(1);
	glm::mat4 projectionMatrix = glm::mat4(1);

	if (position.w == 0.0f)
	{
		viewMatrix = glm::lookAt(glm::vec3(position) * 10.0f, glm::vec3(0), glm::vec3(0, 1, 0));
		projectionMatrix = glm::ortho(-3.0f, 3.0f, 3.0f, -3.0f, 0.2f, 100.0f);
	}
	else
	{
		viewMatrix = glm::lookAt(glm::vec3(position) * 10.0f, glm::vec3(0), glm::vec3(0, 1, 0));
		projectionMatrix = glm::perspective(45.0f, 1.5f, 0.2f, range);
	}

	return glm::inverse(projectionMatrix * viewMatrix);
}