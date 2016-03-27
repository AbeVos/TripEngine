#pragma once
#include <glew/glew.h>
#include "BMPHeader.h"
#include <fstream>
#include <iostream>
#include <string>

namespace TripEngine
{
	namespace Import
	{
		class TextureImporter
		{
		public:
			TextureImporter();
			~TextureImporter();

			static unsigned int ImportTexture(const std::string& path,
				unsigned int width,
				unsigned int height);

		private:

			static void LoadBMPFile(const std::string& path,
				unsigned int& width,
				unsigned int& height,
				unsigned char*& data);
		};



	}
}