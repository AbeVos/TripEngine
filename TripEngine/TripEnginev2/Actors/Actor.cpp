#include "Actor.h"

using namespace TripEngine;
using namespace Actors;

Actor::Actor()
{
	name = "GameObject";

	transform = new Transform();
}

Actor::~Actor()
{

}

void Actor::Update()
{
}

void Actor::AddComponent(ComponentType type, Component* component)
{
	components[type] = component;
}

Component* Actor::GetComponent(ComponentType type)
{
	return components[type];
}