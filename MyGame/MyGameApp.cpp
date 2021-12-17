#include "MyGameApp.h"

MyGameApp::MyGameApp(): mHero("Assets/Textures/Hero.png",0,0,10),
mFrameCounter{ 0 }
{
	mShader.Load("Assets/Shaders/myVertexShader.glsl",
		"Assets/Shaders/myFragmentShader.glsl");
	mShader.SetVec2IntUniform("screenSize", 800, 800);
}

void MyGameApp::OnUpdate()
{
	mHero.UpdatePosition();

	// update existing viruses
	for (auto& monster : mMonsters)
	{
		monster.UpdatePosition();
	}

	// introduce new virus every second 
	if (mFrameCounter % FRAMES_PER_SECOND == 0 && mMonsters.size()<10) {

		int newX{ rand() % 700 };
		int newY{ rand() % 700 };
		Unit::Direction newDir;
		int dirVal{ rand() % 4 };
		if (dirVal == 0)
			newDir = Unit::Direction::Down;
		else if (dirVal == 1)
			newDir = Unit::Direction::Up;
		else if (dirVal == 2)
			newDir = Unit::Direction::Left;
		else if (dirVal == 3)
			newDir = Unit::Direction::Right;
		mMonsters.push_back(Unit{ "Assets/Textures/Monster.png",newX,newY, 10});
		mMonsters.back().SetDirection(newDir);
	}

	// check collisions
	auto it = mMonsters.begin();
	while(it!=mMonsters.end())
	{
		if (mHero.CollideWith(*it))
			it = mMonsters.erase(it);
		else it++;
	}

	for (auto& monsters : mMonsters)
		monsters.Draw(mShader);
	mHero.Draw(mShader);

	mFrameCounter++;
}

void MyGameApp::OnKeyPressed(Suzu::KeyPressedEvent& event)
{
	switch(event.GetKeyCode())
	{
	case SUZU_KEY_LEFT:
		//mHero.SetPosX(mHero.GetPosX() - mHero.GetSpeed());
		mHero.SetDirection(Unit::Direction::Left);
		break;
	case SUZU_KEY_RIGHT:
		//mHero.SetPosX(mHero.GetPosX() + mHero.GetSpeed());
		mHero.SetDirection(Unit::Direction::Right);
		break;
	case SUZU_KEY_DOWN:
		//mHero.SetPosY(mHero.GetPosY() - mHero.GetSpeed());
		mHero.SetDirection(Unit::Direction::Down);
		break;
	case SUZU_KEY_UP:
		//mHero.SetPosY(mHero.GetPosY() + mHero.GetSpeed());
		mHero.SetDirection(Unit::Direction::Up);
		break;
	}
}
