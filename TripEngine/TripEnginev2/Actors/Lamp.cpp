#include "Lamp.h"

using namespace TripEngine;
using namespace Actors;

Lamp::Lamp() : Actor()
{
	Components::Light* light = new Components::Light(transform);
	AddComponent(ct_Light, light);
}

Lamp::~Lamp()
{

}

void Lamp::SetColor(glm::vec3 color)
{
	((Light*)GetComponent(ct_Light))->color = color;
}

void Lamp::SetType(int type)
{
	((Light*)GetComponent(ct_Light))->type = type;
}