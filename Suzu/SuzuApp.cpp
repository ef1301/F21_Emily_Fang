#include "pch.h"

#include "Renderer.h"
#include "SuzuApp.h"
#include "Sprite.h"
#include "Shader.h"
#include "Events.h"

#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"
#include "glad/glad.h"

#include "stb_image.h"

namespace Suzu {
	void SuzuApp::Run()
	{
		SUZU_LOG("Suzu running....");

		mTimeOfNextFrame = std::chrono::steady_clock::now() + mFrameDuration;
		
		while (true) 
		{
			Renderer::ClearFrame();

			OnUpdate();

			std::this_thread::sleep_until(mTimeOfNextFrame);

			mGameWindow.SwapBuffers();

			mGameWindow.PollEvents();

			mTimeOfNextFrame += mFrameDuration;
		}

		Renderer::ShutDown();
	}

	void SuzuApp::OnUpdate()
	{

	}

	void SuzuApp::OnKeyPressed(KeyPressedEvent& event)
	{
		SUZU_LOG(event.GetKeyCode());
	}

	int SuzuApp::GetGameWindowWidth() const
	{
		return mGameWindow.GetWindowWidth();
	}

	int SuzuApp::GetGameWindowHeight() const
	{
		return mGameWindow.GetWindowHeight();
	}

	SuzuApp::SuzuApp()
	{
		mGameWindow.CreateWindow(1200, 900, "Game");

		mGameWindow.SetKeyPressedCallback([this](KeyPressedEvent& event) {
			OnKeyPressed(event);
			});

		Renderer::Init();
	}
}

