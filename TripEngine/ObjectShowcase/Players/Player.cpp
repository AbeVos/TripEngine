#include "Player.h"
#include <iostream>

using namespace Players;
using namespace TripEngine;

Player::Player() : TripEngine::GameObjects::Model("Resources\\Models\\Priest.obj")
{
	speed = 1.0;
}

Player::~Player()
{

}

void Player::Update()
{
	if (Input::GetKeyPressed('w'))
	{
		transform->position.z -= speed * Time::delta();
	}
	else if (Input::GetKeyPressed('s'))
	{
		transform->position.z += speed * Time::delta();
	}

	transformMatrix = glm::mat4(1);
	transformMatrix = glm::scale(transformMatrix, transform->scale);
	transformMatrix = glm::translate(glm::mat4(1), transform->position) * transformMatrix;
}