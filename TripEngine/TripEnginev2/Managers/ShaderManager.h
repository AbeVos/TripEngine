#pragma once
#include <glew\glew.h>
#include <freeglut\freeglut.h>
#include <map>
#include <vector>
#include <fstream>
#include <iostream>

namespace TripEngine
{
	namespace Managers
	{
		class ShaderManager
		{
		private:
			static std::map<std::string, GLuint> programs;

		public:
			ShaderManager();
			~ShaderManager();

		public:
			static void CreateProgram(const std::string& programName, const std::string& vertexShaderFile, const std::string& fragmentShaderFile);
			static const GLuint GetProgram(const std::string& programName);

		private:
			static std::string ReadShader(const std::string& filename);
			static GLuint CreateShader(GLenum shaderType, const std::string& source, const std::string& shaderName);
		};
	}
}