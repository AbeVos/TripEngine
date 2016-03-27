#include "Input.h"

using namespace TripEngine;

glm::vec2 Input::mousePosition;
std::map<unsigned char, bool> Input::keys;

void Input::MouseCallback(int button, int state, int x, int y)
{
	mousePosition = glm::vec2(x, y);
}

void Input::KeyboardCallback(unsigned char key, int x, int y)
{
	keys[key] = true;
	mousePosition = glm::vec2(x, y);
}

void Input::KeyboardUpCallback(unsigned char key, int x, int y)
{
	keys[key] = false;
	mousePosition = glm::vec2(x, y);
}

const glm::vec2& Input::GetMousePosition()
{
	return mousePosition;
}

bool Input::GetKeyPressed(unsigned char key)
{
	return keys[key];
}