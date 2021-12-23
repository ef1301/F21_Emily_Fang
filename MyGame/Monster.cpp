#include "Monster.h"

/*Unit::Direction RandomDirection()
  {
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
    }*/

void Monster::UpdateFacing(Unit::Direction newDir)
{
  mFacing = newDir;
}

void Monster::Move()
{
  /*switch (mDirection)
  {
  case Direction::Left:
    if(IsPositionPossible(mPosX - mSpeed,mPosY)) mPosX -= mSpeed;
    else SetDirection(RandomDirection());
    break;
  case Direction::Right:
    if (IsPositionPossible(mPosX + mSpeed, mPosY)) mPosX += mSpeed;
    else SetDirection(RandomDirection());
    break;
  case Direction::Up:
    if (IsPositionPossible(mPosX, mPosY + mSpeed)) mPosY += mSpeed;
    else SetDirection(RandomDirection());
    break;
  case Direction::Down:
    if (IsPositionPossible(mPosX, mPosY - mSpeed)) mPosY -= mSpeed;
    else SetDirection(RandomDirection());
    break;
    }*/

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
