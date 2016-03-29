#pragma once

namespace TripEngine
{
	namespace Core
	{
		class IListener
		{
		public:
			virtual ~IListener() = 0;

			static void BeginFrame();
			static void DisplayFrame();
			static void EndFrame();
			static void Reshape(int width, int height, int prevWidth, int prevHeight);
		};

		inline IListener::~IListener()
		{

		}
	}
}