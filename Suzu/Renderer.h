#pragma once

#include "pch.h"

#include "Sprite.h"
#include "Shader.h"
#include "RendererImplementation.h"
#include "SuzuUtils.h"

namespace Suzu
{
	class SUZU_API Renderer
	{
	public:
		static void Init();
		static void Draw(Sprite& sprite,
			int xPos, int yPos, // bottom left corner of the sprite
			int width, int height,
			Shader& shader);
		static void ClearFrame();
		static void ShutDown();
	private:
		Renderer();

		// c++17 standard
		inline static Renderer* mInstance{ nullptr };
		inline static std::unique_ptr<RendererImplementation> mImplementation;
	};
}
