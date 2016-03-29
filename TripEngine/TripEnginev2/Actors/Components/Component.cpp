#include "Component.h"

using namespace TripEngine;
using namespace Actors;
using namespace Components;

Component::Component(Transform* transform)
{
	this->transform = transform;
}

Component::~Component()
{

}

Transform* Component::GetTransform()
{
	return transform;
}