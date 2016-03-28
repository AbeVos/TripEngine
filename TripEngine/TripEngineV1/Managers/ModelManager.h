#pragma once
#include <glm\glm.hpp>
#include "..\GameObjects\Model.h"
#include <vector>

namespace TripEngine
{
	namespace Managers
	{
		class ModelManager
		{
		private:
			std::vector<GameObjects::Model*> models;

			glm::mat4* viewMatrix;
			glm::mat4* projectionMatrix;
			glm::mat4* VPMatrix;
			glm::mat4* lightMatrix;

		public:
			ModelManager();
			~ModelManager();

		public:
			void Update();
			void Draw(const glm::vec3& viewPos, const glm::vec4& ambientColor);

			void AddModel(GameObjects::Model* model);

			void SetViewMatrix(glm::mat4* matrix);
			void SetProjectionMatrix(glm::mat4* matrix);
			void SetVPMatrix(glm::mat4* matrix);
			void SetLightMatrix(glm::mat4* matrix);
		};
	}
}