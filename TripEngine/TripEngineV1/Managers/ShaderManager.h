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
			std::map<std::string, GLuint> programs;
		
		public:
			ShaderManager();
			~ShaderManager();

		public:
			void CreateProgram(const std::string& programName, const std::string& vertexShaderFile, const std::string& fragmentShaderFile);
			const GLuint GetProgram(const std::string& programName);

		private:
			std::string ReadShader(const std::string& filename);
			GLuint CreateShader(GLenum shaderType, const std::string& source, const std::string& shaderName);
		};
	}
}