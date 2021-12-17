#pragma once

#include "SuzuUtils.h"
#include "SuzuWindow.h"

#define FRAMES_PER_SECOND 30

namespace Suzu {
	class SUZU_API SuzuApp
	{
	public:
		void Run();
		virtual void OnUpdate();
		virtual void OnKeyPressed(KeyPressedEvent & event);
		int GetGameWindowWidth() const;
		int GetGameWindowHeight() const;
	protected:
		SuzuApp();
	private:
		SuzuWindow mGameWindow;
		
		std::chrono::steady_clock::time_point mTimeOfNextFrame;
		std::chrono::milliseconds mFrameDuration{ 1000 / FRAMES_PER_SECOND };
	};
}


