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