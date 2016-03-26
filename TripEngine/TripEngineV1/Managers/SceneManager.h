#pragma once
#include <glew\glew.h>
#include <glm\glm.hpp>
#include "../Core/Init/IListener.h"
#include "ModelManager.h"
#include "ShaderManager.h"

namespace TripEngine
{
	namespace Managers
	{
		class SceneManager : public Core::IListener
		{
		private:
			Managers::ModelManager* modelManager;
			Managers::ShaderManager* shaderManager;

			unsigned int screenWidth, screenHeight;
			glm::vec4 ambientColor;
			glm::vec4 lightPos;

		public:
			SceneManager();
			~SceneManager();

		public:
			virtual void notifyBeginFrame();
			virtual void notifyDisplayFrame();
			virtual void notifyEndFrame();
			virtual void notifyReshape(int width, int height, int prevWidth, int prevHeight);

			const Managers::ModelManager* GetModelManager();
			const Managers::ShaderManager* GetShaderManager();
		};
	}
}