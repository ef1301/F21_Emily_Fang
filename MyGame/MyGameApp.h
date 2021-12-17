#pragma once

#include "Suzu.h"
#include "Unit.h"

class MyGameApp : public Suzu::SuzuApp
{
public:
	MyGameApp();
	virtual void OnUpdate() override;
	virtual void OnKeyPressed(Suzu::KeyPressedEvent& event) override;

private:
	Unit mHero;
	std::vector<Unit> mMonsters;
	int mFrameCounter;

	Suzu::Shader mShader;
};
