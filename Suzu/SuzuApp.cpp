#include "pch.h"

#include "Renderer.h"
#include "SuzuApp.h"
#include "Sprite.h"
#include "Shader.h"

#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"
#include "glad/glad.h"

#include "stb_image.h"

namespace Suzu {
	void SuzuApp::Run()
	{
		std::cout << "Suzu running...." << std::endl;

		mGameWindow.CreateWindow(800, 600, "Test");

		Renderer::Init();

		// Shaders
		Suzu::Shader myShader;
		myShader.Load("C:/Users/Emily/source/repos/F21_Emily_Fang/Suzu/Assets/Shaders/myVertexShader.glsl",
			"C:/Users/Emily/source/repos/F21_Emily_Fang/Suzu/Assets/Shaders/myFragmentShader.glsl");
		myShader.SetVec2IntUniform("screenSize",
			mGameWindow.GetWindowWidth(),
			mGameWindow.GetWindowHeight());
		// TEXTURE

		Suzu::Sprite fish;
		fish.LoadImage("C:/Users/Emily/source/repos/F21_Emily_Fang/Suzu/Assets/Textures/test.png");

		while (true) 
		{
			Renderer::ClearFrame();

			OnUpdate();

			Renderer::Draw(fish, 100, 50, fish.GetWidth(), fish.GetHeight(), myShader);

			mGameWindow.SwapBuffers();

			mGameWindow.PollEvents();
		}

		Renderer::ShutDown();
	}

	void SuzuApp::OnUpdate()
	{

	}
	SuzuApp::SuzuApp()
	{

	}
}

