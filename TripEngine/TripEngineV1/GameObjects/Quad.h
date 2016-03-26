#pragma once
#include "GameObject.h"
#include "../Managers/ShaderManager.h"
#include "../Rendering/Framebuffer.h"

namespace TripEngine
{
	namespace GameObjects
	{
		class Quad : public GameObject
		{
		private:
			GLuint vao;
			std::vector<GLuint> vbos;
			GLuint program;

		public:
			Quad();
			~Quad();

			void Create();
			virtual void Draw(const unsigned int& color, const unsigned int& depth, const glm::mat4& i_pv_matrix);
			virtual void Update() override final;
		};
	}
}