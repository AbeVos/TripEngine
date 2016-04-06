#include "Priest.h"

using namespace TripEngine;
using namespace Actors;

Priest::Priest() : Actor()
{
	Components::Model* cube = new Components::Model(transform ,"Resources\\Models\\Priest.obj");
	AddComponent(ct_Model, cube);
}

Priest::~Priest()
{

}