#pragma once

#include "Suzu.h"
#include "Unit.h"
#include "Hero.h"
#include "Monster.h"

class MyGameApp : public Suzu::SuzuApp
{
public:
	MyGameApp();
	virtual void OnUpdate() override;
	virtual void OnKeyPressed(Suzu::KeyPressedEvent& event) override;

private:
	Hero mHero;
  Unit mBackground;
	std::vector<Monster> mMonsters;
	int mFrameCounter;

  Suzu::Shader mShader;
	Suzu::Shader mLeftShader;
	Suzu::Shader mRightShader;
};
