#include "InitGLEW.h"

using namespace TripEngine;
using namespace Core;
using namespace Init;

void InitGLEW::Init()
{
	glewExperimental = true;
	if (glewInit() == GLEW_OK)
	{
		std::cout << "GLEW: Initialize" << std::endl;
	}
}