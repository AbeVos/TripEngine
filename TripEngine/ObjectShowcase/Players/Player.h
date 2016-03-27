#pragma once
#include <TripEngineV1\GameObjects\Model.h>
#include <TripEngineV1\Input.h>
#include <TripEngineV1\Time.h>

namespace Players
{
	class Player : public TripEngine::GameObjects::Model
	{
	private:
		float speed;

	public:
		Player();
		virtual ~Player();

		virtual void Update();
	};
}