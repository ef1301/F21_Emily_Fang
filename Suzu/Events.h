#pragma once

#include "SuzuUtils.h"

namespace Suzu
{
	class KeyPressedEvent
	{
	public:
		KeyPressedEvent(int keyCode);
		int GetKeyCode() const;

	private:
		int mKeyCode{ -1 };
	};
}