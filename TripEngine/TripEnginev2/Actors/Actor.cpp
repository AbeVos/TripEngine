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