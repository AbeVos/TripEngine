#include "TimeManager.h"

using namespace TripEngine;
using namespace Managers;

double TimeManager::previousTime = 0.0f;
double TimeManager::currentTime = 0.0f;

void TimeManager::Update()
{
	previousTime = currentTime;
	currentTime = glutGet(GLUT_ELAPSED_TIME);
}

const double& TimeManager::time()
{
	return 0.001 * currentTime;
}

const double& TimeManager::delta()
{
	return 0.001 * (currentTime - previousTime);
}