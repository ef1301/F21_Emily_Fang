#pragma once

#include "SuzuUtils.h"
#include "SuzuApp.h"
#include "SuzuWindow.h"
#include "Sprite.h"
#include "Renderer.h"
#include "Events.h"
#include "KeyCodes.h"

#define START_SUZU_GAME(classname) \
int main()\
{\
	classname _suzu_game;\
	_suzu_game.Run();\
}