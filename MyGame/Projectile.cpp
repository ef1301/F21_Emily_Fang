#include "Projectile.h"

void Projectile::UpdatePosition()
{
  switch (mDirection)
    {
    case Direction::Left:
      if(IsPositionPossible(mPosX - mSpeed,mPosY)) mPosX -= mSpeed;
      break;
    case Direction::Right:
      if (IsPositionPossible(mPosX + mSpeed, mPosY)) mPosX += mSpeed;
      break;
    }
}
