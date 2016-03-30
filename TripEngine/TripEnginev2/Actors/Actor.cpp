#include "Actor.h"

using namespace TripEngine;
using namespace Actors;

Actor::Actor()
{
	name = "GameObject";

	transform = new Transform();
	
	components[Transform] = transform;
}

Actor::~Actor()
{

}

void Actor::Update()
{
}

void Actor::AddComponent(ComponentType type, Component* component)
{
	component[type] = component;
}

const Component& Actor::GetComponent(ComponentType type)
{
	return components[type];
}