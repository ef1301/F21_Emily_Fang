#pragma once

#include "Suzu.h"
#include "Unit.h"
#include "Monster.h"

class MyGameApp : public Suzu::SuzuApp
{
public:
	MyGameApp();
	virtual void OnUpdate() override;
	virtual void OnKeyPressed(Suzu::KeyPressedEvent& event) override;

private:
	Unit mHero;
	std::vector<Monster> mMonsters;
	int mFrameCounter;

	Suzu::Shader mLeftShader;
	Suzu::Shader mRightShader;
};