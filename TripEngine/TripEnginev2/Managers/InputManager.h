#pragma once
#include <glew\glew.h>
#include <glm\glm.hpp>
#include <map>

namespace TripEngine
{
	namespace Managers
	{
		class InputManager
		{
		private:
			static glm::vec2 mousePosition;
			static unsigned char pressedKey;
			static std::map<unsigned char, bool> keys;

		public:
			static void MouseCallback(int button, int state, int x, int y);
			static void KeyboardCallback(unsigned char key, int x, int y);
			static void KeyboardUpCallback(unsigned char key, int x, int y);

		public:
			static const glm::vec2& GetMousePosition();

			static bool GetKeyPressed(unsigned char key);
		};
	}
}