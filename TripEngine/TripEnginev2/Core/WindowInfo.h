#pragma once
#include <string>

namespace TripEngine
{
	namespace Core
	{
		struct WindowInfo
		{
			std::string name;
			int width, height;
			int xPos, yPos;
			bool isReshapable;

			WindowInfo()
			{
				name = "TripEngine Application";
				width = 800;
				height = 600;
				xPos = 100;
				yPos = 100;
				isReshapable = true;
			}

			WindowInfo(std::string name, int xPosStart, int yPosStart,
				int width, int height, bool isReshapable)
			{
				this->name = name;
				this->xPos = xPosStart;
				this->yPos = yPosStart;

				this->width = width;
				this->height = height;
				this->isReshapable = isReshapable;
			}

			WindowInfo(const WindowInfo& windowInfo)
			{
				name = windowInfo.name;
				xPos = windowInfo.xPos;
				yPos = windowInfo.yPos;

				width = windowInfo.width;
				height = windowInfo.height;
				isReshapable = windowInfo.isReshapable;
			}

			void operator=(const WindowInfo& windowInfo)
			{
				name = windowInfo.name;
				xPos = windowInfo.xPos;
				yPos = windowInfo.yPos;

				width = windowInfo.width;
				height = windowInfo.height;
				isReshapable = windowInfo.isReshapable;
			}
		};
	}
}