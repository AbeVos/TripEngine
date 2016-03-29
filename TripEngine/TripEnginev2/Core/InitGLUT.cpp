#include "InitGLUT.h"

using namespace TripEngine;
using namespace Core;
using namespace Managers;

//Core::IListener* InitGLUT::listener = NULL;
Core::WindowInfo InitGLUT::windowInformation;

double lastTime = 0;
int nbFrames = 0;

void InitGLUT::Init(const Core::WindowInfo& windowInfo,
	const Core::ContextInfo& contextInfo,
	const Core::FramebufferInfo& framebufferInfo)
{
	int fakeargc = 1;
	char *fakeargv[] = { "fake", NULL };
	glutInit(&fakeargc, fakeargv);

	if (contextInfo.core)
	{
		glutInitContextVersion(contextInfo.versionMajor, contextInfo.versionMinor);
		glutInitContextProfile(GLUT_CORE_PROFILE);
	}
	else
	{
		glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);
	}

	windowInformation = windowInfo;
	glutInitDisplayMode(framebufferInfo.flags);
	glutInitWindowPosition(windowInfo.xPos, windowInfo.yPos);
	glutInitWindowSize(windowInfo.width, windowInfo.height);

	glutCreateWindow(windowInfo.name.c_str());

	std::cout << "GLUT: Initialized" << std::endl;

	glutIdleFunc(IdleCallback);
	glutCloseFunc(CloseCallback);
	glutDisplayFunc(DisplayCallback);
	glutReshapeFunc(ReshapeCallback);

	glutMouseFunc(Managers::InputManager::MouseCallback);
	glutKeyboardFunc(Managers::InputManager::KeyboardCallback);
	glutKeyboardUpFunc(Managers::InputManager::KeyboardUpCallback);

	Init::InitGLEW::Init();

	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE,
		GLUT_ACTION_GLUTMAINLOOP_RETURNS);

	PrintOpenGLInfo(windowInfo, contextInfo);
}

void InitGLUT::Run()
{
	std::cout << "GLUT:\t Start Running" << std::endl;
	glutMainLoop();
}

void InitGLUT::Close()
{
	std::cout << "GLUT:\t Finished" << std::endl;
	glutLeaveMainLoop();
}

void InitGLUT::IdleCallback(void)
{
	glutPostRedisplay();
}

void InitGLUT::DisplayCallback()
{
	double currentTime = glutGet(GLUT_ELAPSED_TIME);

	nbFrames++;
	if (currentTime - lastTime >= 1000)
	{
		printf("%f ms/frame\n", 1000.0 / double(nbFrames));
		nbFrames = 0;
		lastTime += 1000;

		printf("Time: %f s.\n", Managers::TimeManager::time());
	}

	Managers::TimeManager::Update();


	SceneManager::BeginFrame();
	SceneManager::DisplayFrame();

	glutSwapBuffers();

	SceneManager::EndFrame();
}

void InitGLUT::ReshapeCallback(int width, int height)
{
	if (windowInformation.isReshapable == true)
	{
		SceneManager::Reshape(width, height, windowInformation.width, windowInformation.height);
		
		windowInformation.width = width;
		windowInformation.height = height;
	}
}

void InitGLUT::CloseCallback()
{
	Close();
}

void InitGLUT::EnterFullScreen()
{
	glutFullScreen();
}

void InitGLUT::ExitFullScreen()
{
	glutLeaveFullScreen();
}

void InitGLUT::PrintOpenGLInfo(const Core::WindowInfo& windowInfo,
	const Core::ContextInfo& contextInfo)
{
	const unsigned char* renderer = glGetString(GL_RENDERER);
	const unsigned char* vendor = glGetString(GL_VENDOR);
	const unsigned char* version = glGetString(GL_VERSION);

	std::cout << "******************************************************************" << std::endl;
	std::cout << "GLUT:\tInitialize" << std::endl;
	std::cout << "GLUT:\tVendor: " << vendor << std::endl;
	std::cout << "GLUT:\tRenderer: " << renderer << std::endl;
	std::cout << "GLUT:\tOpenGl version: " << version << std::endl;
	std::cout << "******************************************************************" << std::endl;
}