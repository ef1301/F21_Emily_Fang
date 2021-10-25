#include "pch.h"

#include "SuzuApp.h"

#include "GLFW/glfw3.h"

namespace Suzu {
	void SuzuApp::Run()
	{
		std::cout << "Suzu running...." << std::endl;

		mGameWindow.CreateWindow(800, 600, "Test");

		while (true) 
		{
			OnUpdate();

			mGameWindow.SwapBuffers();
			mGameWindow.PollEvents();

		}
	}

	void SuzuApp::OnUpdate()
	{

	}
	SuzuApp::SuzuApp()
	{

	}
}

