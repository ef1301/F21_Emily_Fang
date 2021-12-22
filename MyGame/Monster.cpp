#include "Monster.h"

void Monster::Move() {
    switch (mDirection)
    {
    case Direction::Left:
      mPosX -= mSpeed;
      break;
    case Direction::Right:
      mPosX += mSpeed;
      break;
    case Direction::Up:
      mPosY += mSpeed;
      break;
    case Direction::Down:
      mPosY -= mSpeed;
      break;
    }
}

void Monster::UpdatePosition() {
  Move();
  UpdateFacing();
}
