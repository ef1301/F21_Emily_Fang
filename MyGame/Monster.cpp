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


void Monster::UpdatePosition() {
  switch (mDirection)
    {
    case Direction::Left:
      if(IsPositionPossible(mPosX - mSpeed,mPosY)) mPosX -= mSpeed;
      break;
    case Direction::Right:
      if (IsPositionPossible(mPosX + mSpeed, mPosY)) mPosX += mSpeed;
      break;
    case Direction::Up:
      if (IsPositionPossible(mPosX, mPosY + mSpeed)) mPosY += mSpeed;
      break;
    case Direction::Down:
      if (IsPositionPossible(mPosX, mPosY - mSpeed)) mPosY -= mSpeed;
      else {

        break;
      }
    }

  if(IsAtEdge())
    {
      Unit::Direction newDir;
      int dirVal{ rand() % 4 };
      if (dirVal == 0)
        SetDirection(Unit::Direction::Down);
          //mDirection = Unit::Direction::Down;
      else if (dirVal == 1)
        SetDirection(Unit::Direction::Up);
        //mDirection = Unit::Direction::Up;
      else if (dirVal == 2)
        SetDirection(Unit::Direction::Left);
        // mDirection = Unit::Direction::Left;
      else
        SetDirection(Unit::Direction::Right);
        //mDirection = Unit::Direction::Right;
      UpdatePosition();
  }
  UpdateFacing();
}
