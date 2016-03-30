#include "CameraObject.h"

using namespace TripEngine;
using namespace Actors;

CameraObject::CameraObject() : Actor()
{
	Components::Camera* camera = new Components::Camera(transform);
	AddComponent(ct_Camera, camera);
}

CameraObject::~CameraObject()
{

}