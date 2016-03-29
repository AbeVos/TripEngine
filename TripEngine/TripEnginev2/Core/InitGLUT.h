#pragma once
#include "ContextInfo.h"
#include "FrameBufferInfo.h"
#include "WindowInfo.h"
#include "InitGLEW.h"
#include "IListener.h"
#include "..\Managers\SceneManager.h"
#include "..\Managers\InputManager.h"
#include "..\Managers\TimeManager.h"
#include <iostream>

namespace TripEngine
{
	namespace Core
	{
		class InitGLUT
		{
		public:
			static void Init(const Core::WindowInfo& window,
				const ContextInfo& context,
				const FramebufferInfo& framebufferInfo);

			static void Run();
			static void Close();

			static void EnterFullScreen();
			static void ExitFullScreen();

			static void PrintOpenGLInfo(const Core::WindowInfo& windowInfo,
				const Core::ContextInfo& context);

		private:
			//static IListener* listener;
			static WindowInfo windowInformation;

			static void IdleCallback(void);
			static void DisplayCallback(void);
			static void ReshapeCallback(int width, int height);
			static void CloseCallback();
		};
	}
}