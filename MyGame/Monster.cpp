#include "Monster.h"

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

void Monster::Move() {
    switch (mDirection)
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
  }
}

void Monster::UpdatePosition() {
  Move();
  UpdateFacing();
}
