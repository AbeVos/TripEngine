#pragma once
#include <glew\glew.h>
#include <glm\glm.hpp>
#include "Component.h"
#include "..\..\Managers\LightManager.h"
#include <vector>

namespace TripEngine
{
	namespace Actors
	{
		namespace Components
		{
			class Model : public Component
			{
			protected:
				glm::mat4* viewMatrix;
				glm::mat4* projectionMatrix;
				glm::mat4* VPMatrix;
				glm::mat4* lightMatrix;

				GLuint vao;
				std::vector<GLuint> vbos;
				GLuint program;
				unsigned int textureDiffuse;
				unsigned int textureNormal;

				unsigned int numVertices;

			public:
				Model(const char* path);
				virtual ~Model();

			private:
				template <typename T>
				void SetLightUniform(GLuint program, const char* name, int index, const T& value);

			public:
				virtual void Draw(const glm::vec3& viewPos, const glm::vec4& ambientColor);

				virtual void SetProgram(GLuint program);
				virtual void SetDiffuse(unsigned int texture);
				virtual void SetNormal(unsigned int texture);

				virtual GLuint GetVao();
				virtual const std::vector<GLuint>& GetVbos();

				virtual void SetViewMatrix(glm::mat4* matrix);
				virtual void SetProjectionMatrix(glm::mat4* matrix);
				virtual void SetVPMatrix(glm::mat4* matrix);
				virtual void SetLightMatrix(glm::mat4* matrix);
			};
		}
	}
}