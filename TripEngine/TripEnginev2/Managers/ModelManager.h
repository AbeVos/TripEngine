#pragma once
#include "..\Actors\Components\Model.h"
#include <vector>

namespace TripEngine
{
	namespace Managers
	{
		class ModelManager
		{
		private:
			static std::vector<Actors::Components::Model*> models;

		private:
			static void SetMatrices();

		public:
			static void Update();
			static void Draw(const glm::vec4& ambientColor);

			static void AddModel(Actors::Components::Model* model);
		};
	}
}