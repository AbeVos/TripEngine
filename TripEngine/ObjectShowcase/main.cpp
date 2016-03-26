#pragma once
#include <TripEngineV1\Engine.h>

using namespace TripEngine;

int main(int argc, char **argv)
{
	Engine* engine = new Engine();

	engine->Run();

	return 0;
}