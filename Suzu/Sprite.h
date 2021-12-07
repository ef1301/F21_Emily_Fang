#pragma once

#include "pch.h"
#include "SuzuUtils.h"
#include "SpriteImplementation.h"

namespace Suzu
{
	class SUZU_API Sprite
	{
	public:
		Sprite();

		void LoadImage(const std::string& pictureFile);
		int GetWidth() const;
		int GetHeight() const;
		void Bind();

	private:
		std::unique_ptr<SpriteImplementation> mSpriteImplementation;

	};
}

