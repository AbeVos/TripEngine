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
		protected:
			glm::mat4* viewMatrix;
			glm::mat4* projectionMatrix;

			GLuint vao;
			std::vector<GLuint> vbos;
			GLuint program;

			unsigned int numVertices;

			GLuint texture;

		public:
			Model(const char* path);
			virtual ~Model();

		public:
			virtual void Draw(const glm::vec3& viewPos, const glm::vec3& lightPos, const glm::vec4& ambientColor);

			virtual void SetProgram(GLuint program);

			virtual GLuint GetVao();
			virtual const std::vector<GLuint>& GetVbos();

			virtual void SetViewMatrix(glm::mat4* matrix);
			virtual void SetProjectionMatrix(glm::mat4* matrix);
		};
	}
}