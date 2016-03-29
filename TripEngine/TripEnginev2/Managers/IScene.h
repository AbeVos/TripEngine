#pragma once


namespace TripEngine
{
	namespace Managers
	{
		class IScene
		{
		public:
			IScene();
			virtual ~IScene();

			virtual void Update() = 0;
			virtual void Draw() = 0;
		};
	}
}