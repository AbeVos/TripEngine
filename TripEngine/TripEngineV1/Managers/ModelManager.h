#pragma once
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

		public:
			ModelManager();
			~ModelManager();

		public:
			void Update();
			void Draw();

			void AddModel(GameObjects::Model* model);
		};
	}
}