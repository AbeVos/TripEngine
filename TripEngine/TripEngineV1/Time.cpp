#include "Time.h"

using namespace TripEngine;

float Time::previousTime = 0.0f;
float Time::currentTime = 0.0f;

void Time::Update()
{
	previousTime = currentTime;
	currentTime = glutGet(GLUT_ELAPSED_TIME);
}

const float& Time::time()
{
	return 0.001 * currentTime;
}

const float& Time::delta()
{
	return 0.001 * (currentTime - previousTime);
}