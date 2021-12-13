#include "pch.h"

#include "Renderer.h"
#include "SuzuApp.h"
#include "Sprite.h"
#include "Shader.h"
//#include "Events.h"

#define GLFW_INCLUDE_NONE
//#include "GLFW/glfw3.h"
#include "glad/glad.h"

#include "stb_image.h"

namespace Suzu {
	void SuzuApp::Run()
	{
		SUZU_LOG("Suzu running....");

		mGameWindow.CreateWindow(800, 600, "Test");

		mGameWindow.SetKeyPressedCallback([this](KeyPressedEvent& event) {
			OnKeyPressed(event);
			});
			
		Renderer::Init();

		// Shaders
		Suzu::Shader myShader;
		myShader.Load("Assets/Shaders/myVertexShader.glsl",
			"Assets/Shaders/myFragmentShader.glsl");
		myShader.SetVec2IntUniform("screenSize",
			mGameWindow.GetWindowWidth(),
			mGameWindow.GetWindowHeight());
		// TEXTURE

		Suzu::Sprite fish;
		fish.LoadImage("Assets/Textures/test.png");

		mTimeOfNextFrame = std::chrono::steady_clock::now() + mFrameDuration;

		while (true) 
		{
			Renderer::ClearFrame();

			OnUpdate();

			Renderer::Draw(fish, 100, 50, fish.GetWidth(), fish.GetHeight(), myShader);

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

	SuzuApp::SuzuApp()
	{

	}
}

