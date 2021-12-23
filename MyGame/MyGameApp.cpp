#include "MyGameApp.h"

MyGameApp::MyGameApp(): mHero("Assets/Textures/Hero.png",0,0,10),
                        mBackground("Assets/Textures/Background.png",0,0),
                        mFrameCounter{ 0 }
{
  mShader.Load("Assets/Shaders/myVertexShader.glsl",
		"Assets/Shaders/myFragmentShader.glsl");
	mShader.SetVec2IntUniform("screenSize", 800, 800);
  
	mLeftShader.Load("Assets/Shaders/myLeftVertexShader.glsl",
		"Assets/Shaders/myFragmentShader.glsl");
	mLeftShader.SetVec2IntUniform("screenSize", 800, 800);

	mRightShader.Load("Assets/Shaders/myRightVertexShader.glsl",
		"Assets/Shaders/myFragmentShader.glsl");
	mRightShader.SetVec2IntUniform("screenSize", 800, 800);
  
}

void NewMonster(std::vector<Monster>& monsters)
{
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
		monsters.push_back(Monster{ "Assets/Textures/Monster.png",newX,newY, 10});
		monsters.back().SetDirection(newDir);
}

Unit::Direction RandomDirection() {
  Unit::Direction newDir;
  int dirVal{ rand() % 4 };
  if (dirVal == 0)
    return Unit::Direction::Down;
  else if (dirVal == 1)
    return Unit::Direction::Up;
  else if (dirVal == 2)
    return Unit::Direction::Left;
  else
    return Unit::Direction::Right;
}

void MyGameApp::OnUpdate()
{
  mBackground.Draw(mShader);
	mHero.UpdatePosition();

	// update existing viruses
	for (auto& monster : mMonsters)
	{
		monster.UpdatePosition();
	}

	// introduce new virus every second 
	if (mFrameCounter % FRAMES_PER_SECOND == 0 && mMonsters.size()<10) {
    NewMonster(mMonsters);
	}

	// check collisions
	auto it = mMonsters.begin();
	while(it!=mMonsters.end())
	{
    if (mHero.CollideWith(*it)) {
      it = mMonsters.erase(it);
    }
    else if (it->IsAtEdge()) {
      it->SetDirection(RandomDirection());
      it->UpdatePosition();
    }
		else it++;
	}

	for (auto& monsters : mMonsters)
    {
        if(monsters.GetFacing() == Unit::Direction::Left) monsters.Draw(mLeftShader);
        else monsters.Draw(mRightShader);
    }
  
  if(mHero.GetFacing() == Unit::Direction::Left) mHero.Draw(mLeftShader);
  if(mHero.GetFacing() == Unit::Direction::Right) mHero.Draw(mRightShader);

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
