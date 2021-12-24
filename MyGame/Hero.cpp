#include "Hero.h"

void Hero::Shoot()
{
  mBullets.push_back(Projectile{"Assets/Textures/Bullet.png",mPosX,mPosY,15});
  mBullets.back().SetDirection(GetFacing());
}

void Hero::UpdateBullets(Suzu::Shader& shader)
{
  for (auto& bullet : mBullets)
    {
      bullet.UpdatePosition();
    }

  for (auto& bullet : mBullets)
    {
      bullet.Draw(shader);
    }
}
