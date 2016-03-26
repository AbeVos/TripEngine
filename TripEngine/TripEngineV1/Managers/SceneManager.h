#pragma once
#include <glew\glew.h>
#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>
#include "../Core/Init/IListener.h"
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
			std::string currentScene;
			std::map<std::string, IScene*> scenes;

		public:
			SceneManager();
			~SceneManager();

		public:
			virtual void notifyBeginFrame();
			virtual void notifyDisplayFrame();
			virtual void notifyEndFrame();
			virtual void notifyReshape(int width, int height, int prevWidth, int prevHeight);

			void CreateScene(const std::string& name, IScene* scene);
			void SetCurrentScene(const std::string& name);

			const Managers::IScene* GetCurrentScene();
		};
	}
}