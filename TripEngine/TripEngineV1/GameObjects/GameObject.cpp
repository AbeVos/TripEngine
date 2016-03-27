#include "GameObject.h"

using namespace TripEngine;
using namespace GameObjects;

GameObject::GameObject()
{
	name = "GameObject";
	transform = new Transform();
	transformMatrix = glm::mat4(1);
}

GameObject::~GameObject()
{

}

void GameObject::Update()
{
	transformMatrix = glm::mat4(1);
	transformMatrix = glm::scale(transformMatrix, transform->scale);
	transformMatrix = glm::translate(glm::mat4(1), transform->position) * transformMatrix;
}

void GameObject::Translate(const glm::vec3& offset)
{
	transform->position += offset;
}

void GameObject::Scale(const glm::vec3& scale)
{
	transform->scale *= scale;
}