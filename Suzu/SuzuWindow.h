#pragma once

#include "pch.h"
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
		void SetKeyPressedCallback(std::function<void(KeyPressedEvent& )> func);
	private:
		std::unique_ptr<WindowImplementation> mWindow;
	};
}
