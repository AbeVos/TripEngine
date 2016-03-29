#pragma once
#define _CRT_SECURE_NO_DEPRECATE
#include <glm\glm.hpp>
#include "..\Render\Vertex.h"
#include <iostream>
#include <vector>

namespace TripEngine
{
	namespace Import
	{
		class OBJImporter
		{
		public:
			static bool ImportOBJ(const char* path, std::vector<Render::Vertex>& out_vertices);
		};
	}
}