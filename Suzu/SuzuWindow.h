#pragma once

#include "SuzuUtils.h"
#include "WindowImplementation.h"

namespace Suzu
{
	class SUZU_API SuzuWindow
	{
	public:
		SuzuWindow();
		void CreateWindow(int width, int height, const std::string& name);
		void SwapBuffers();
		void PollEvents();
		int GetWindowWidth() const;
		int GetWindowHeight() const;
	
	private:
		WindowImplementation* mWindow;
	};
}
