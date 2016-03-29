#pragma once
#include <glew\glew.h>
#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>
#include "../Core/IListener.h"
#include "IScene.h"
#include "ModelManager.h"
#include "ShaderManager.h"
#include <map>

namespace TripEngine
{
	namespace Managers
	{
		class SceneManager : public Core::IListener
		{
		private:
			static std::string currentScene;
			static std::map<std::string, IScene*> scenes;

		public:
			static void Init();

			static void notifyBeginFrame();
			static void notifyDisplayFrame();
			static void notifyEndFrame();
			static void notifyReshape(int width, int height, int prevWidth, int prevHeight);

			static void CreateScene(const std::string& name, IScene* scene);
			static void SetCurrentScene(const std::string& name);

			static const Managers::IScene* GetCurrentScene();

			static void DeleteSceneManager();
		};
	}
}