#pragma once

namespace TripEngine
{
	namespace Core
	{
		class IListener
		{
		public:
			virtual ~IListener() = 0;

			virtual void BeginFrame() = 0;
			virtual void DisplayFrame() = 0;
			virtual void EndFrame() = 0;
			virtual void Reshape(int width, int height, int prevWidth, int prevHeight) = 0;
		};

		inline IListener::~IListener()
		{

		}
	}
}