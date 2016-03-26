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
	transformMatrix = glm::translate(glm::mat4(1), transform->position);
}

void GameObject::Translate(const glm::vec3& offset)
{
	transform->position += offset;
}