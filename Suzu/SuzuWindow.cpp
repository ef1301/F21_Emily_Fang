#include "pch.h"
#include "SuzuWindow.h"
#include "GLFWimpl/GlfwImplementation.h"

namespace Suzu
{
	SuzuWindow::SuzuWindow()
	{
#ifdef SUZU_WINDOWS
		mWindow = std::unique_ptr<WindowImplementation>{ new GlfwImplementation() };
#elif SUZU_MAC
		mWindow = std::unique_ptr<WindowImplementation>{ new GlfwImplementation() };
#elif SUZU_LINUX
		mWindow = std::unique_ptr<WindowImplementation>{ new GlfwImplementation() };
#else
		#only_Windows_Linux_Mac are supported
#endif 
		

		mWindow->Init();
	}

	void SuzuWindow::CreateWindow(int width, int height, const std::string& name)
	{
		mWindow->CreateWindow(width, height, name);
	}

	void SuzuWindow::SwapBuffers()
	{
		mWindow->SwapBuffers();
	}

	void SuzuWindow::PollEvents()
	{
		mWindow->PollEvents();
	}

	int SuzuWindow::GetWindowWidth() const
	{
		return mWindow->GetWindowWidth();
	}

	int SuzuWindow::GetWindowHeight() const
	{
		return mWindow->GetWindowHeight();
	}

	void SuzuWindow::SetKeyPressedCallback(std::function<void(KeyPressedEvent&)> func)
	{
		mWindow->SetKeyPressedCallback(func);
	}

}