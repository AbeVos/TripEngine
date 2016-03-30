#include "Cube.h"

using namespace TripEngine;
using namespace Actors;

Cube::Cube() : Actor()
{
	Components::Model* cube = new Components::Model(transform ,"Resources\\Models\\Platform.obj");
	AddComponent(ct_Model, cube);
}

Cube::~Cube()
{

}