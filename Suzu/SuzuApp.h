#pragma once

#include "SuzuUtils.h"
#include "SuzuWindow.h"

namespace Suzu {
	class SUZU_API SuzuApp
	{
	public:
		void Run();
		virtual void OnUpdate();
	protected:
		SuzuApp();
	private:
		SuzuWindow mGameWindow;
	};
}


