#include "Actor.h"

using namespace TripEngine;
using namespace Actors;

Actor::Actor()
{
	name = "GameObject";

	transform = new Transform();
	
	components[ComponentTypes::Transform] = transform;
}

Actor::~Actor()
{

}

void Actor::Update()
{
}