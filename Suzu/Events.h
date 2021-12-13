#pragma once

#include "SuzuUtils.h"

namespace Suzu
{
	class SUZU_API KeyPressedEvent
	{
	public:
		KeyPressedEvent(int keyCode);
		int GetKeyCode() const;

	private:
		int mKeyCode{ -1 };
	};
}