#pragma once
#include "Actor.h"
#include "..\Managers\ShaderManager.h"
#include <vector>

namespace TripEngine
{
	namespace Actors
	{
		class Quad : public Actor
		{
		private:
			GLuint vao;
			std::vector<GLuint> vbos;
			GLuint program;

		public:
			Quad();
			~Quad();

			void Create();
			virtual void Draw(const unsigned int& color, const unsigned int& depth, const int& pass, const int& width, const int& height);
			virtual void Update() override final;
		};
	}
}