#pragma once
#include <glew\glew.h>
#include "../Core/Init/IListener.h"

namespace TripEngine
{
	namespace Managers
	{
		class SceneManager : public Core::IListener
		{
		private:
			unsigned int screenWidth, screenHeight;

		public:
			SceneManager();
			~SceneManager();

		public:
			virtual void notifyBeginFrame();
			virtual void notifyDisplayFrame();
			virtual void notifyEndFrame();
			virtual void notifyReshape(int width, int height, int prevWidth, int prevHeight);
		};
	}
}