#pragma once

namespace TripEngine
{
	namespace Core
	{
		class IListener
		{
		public:
			virtual ~IListener() = 0;

			virtual void notifyBeginFrame() = 0;
			virtual void notifyDisplayFrame() = 0;
			virtual void notifyEndFrame() = 0;
			virtual void notifyReshape(int width, int height, int prevWidth, int prevHeight) = 0;
		};

		inline IListener::~IListener()
		{

		}
	}
}