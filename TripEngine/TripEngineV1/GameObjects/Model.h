#pragma once
#include <glew\glew.h>
#include "GameObject.h"
#include <vector>

namespace TripEngine
{
	namespace GameObjects
	{
		class Model : public GameObject
		{
		private:
			glm::mat4 viewMatrix;
			glm::mat4 projectionMatrix;

			GLuint vao;
			std::vector<GLuint> vbos;
			GLuint program;

			unsigned int numVertices;

			GLuint texture;

		public:
			Model();
			Model(const char* path);
			virtual ~Model();

		public:
			virtual void Draw();
			virtual void Update() override;

			virtual void SetProgram(GLuint program);

			virtual GLuint GetVao();
			virtual const std::vector<GLuint>& GetVbos();
		};
	}
}