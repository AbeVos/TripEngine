#pragma once
#include "ModelManager.h"
#include "ShaderManager.h"
#include "../Rendering/Light.h"
#include "../GameObjects/Camera.h"
#include <map>
#include <string>

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

			std::map<std::string, Rendering::Light*> lights;

			Managers::ModelManager* modelManager;
		};

		inline IScene::~IScene()
		{

		}
	}
}