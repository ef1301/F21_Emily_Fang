#include "Monster.h"

void Monster::UpdateFacing(Unit::Direction newDir)
{
  mFacing = newDir;
}

void Monster::Move()
{
  int x = mSpeed * cos(mAngle);
  int y = mSpeed * sin(mAngle);
  if (IsPositionPossible(mPosX + x, mPosY + y))
    {
      if(x < 0) UpdateFacing(Unit::Direction::Left);
      else UpdateFacing(Unit::Direction::Right);
      mPosX += x;
      mPosY += y;
  }
  else
    {
      mAngle = rand() % 360;
    }
}

void Monster::UpdatePosition()
{
  Move();
}
