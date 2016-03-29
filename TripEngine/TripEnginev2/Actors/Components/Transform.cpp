#include "Transform.h"

using namespace TripEngine;
using namespace Actors;
using namespace Components;

Transform::Transform() : Component(this)
{
	transformMatrix = new glm::mat4(1);

	position = glm::vec3(0);
	rotation = glm::vec3(0);
	scale = glm::vec3(1);
}

Transform::Transform(glm::vec3 position, glm::vec3 rotation, glm::vec3 scale) : Component(this)
{
	transformMatrix = new glm::mat4(1);

	this->position = position;
	this->rotation = rotation;
	this->scale = scale;
}

Transform::~Transform()
{

}

glm::mat4* Transform::GetTransformMatrix()
{
	CalculateTransformMatrix();
	return transformMatrix;
}

void Transform::CalculateTransformMatrix()
{
	glm::mat4 scale = glm::scale(glm::mat4(1), this->scale);
	glm::mat4 rotation = glm::rotate(glm::mat4(1), this->rotation.y, glm::vec3(0, 1, 0)) *	//	Third rotation
						 glm::rotate(glm::mat4(1), this->rotation.x, glm::vec3(1, 0, 0)) *	//	Second rotation
						 glm::rotate(glm::mat4(1), this->rotation.z, glm::vec3(0, 0, 1));	//	First rotation
	glm::mat4 position = glm::translate(glm::mat4(1), this->position);

	*transformMatrix = position * rotation * scale * glm::mat4(1);
}