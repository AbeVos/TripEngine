#pragma once
#include "ModelManager.h"
#include "ShaderManager.h"
#include "../GameObjects/Camera.h"

namespace TripEngine
{
	namespace Managers
	{
		class IScene
		{
		public:
			virtual ~IScene() = 0;

			virtual void Update() = 0;
			virtual void Draw() = 0;

		protected:
			GameObjects::Camera camera;

			glm::mat4* viewMatrix;
			glm::mat4* projectionMatrix;

			glm::vec4* ambientColor;
			glm::vec3* lightPos;

			Managers::ModelManager* modelManager;
		};

		inline IScene::~IScene()
		{

		}
	}
}