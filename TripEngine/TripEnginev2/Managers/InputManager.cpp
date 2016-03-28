#include "InputManager.h"

using namespace TripEngine;
using namespace Managers;

glm::vec2 InputManager::mousePosition;
std::map<unsigned char, bool> InputManager::keys;

void InputManager::MouseCallback(int button, int state, int x, int y)
{
	mousePosition = glm::vec2(x, y);
}

void InputManager::KeyboardCallback(unsigned char key, int x, int y)
{
	keys[key] = true;
	mousePosition = glm::vec2(x, y);
}

void InputManager::KeyboardUpCallback(unsigned char key, int x, int y)
{
	keys[key] = false;
	mousePosition = glm::vec2(x, y);
}

const glm::vec2& InputManager::GetMousePosition()
{
	return mousePosition;
}

bool InputManager::GetKeyPressed(unsigned char key)
{
	return keys[key];
}