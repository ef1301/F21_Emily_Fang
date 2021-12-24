#pragma once

#include "Suzu.h"
#include "Unit.h"
#include "Projectile.h"

class Hero: public Unit {
  using Unit::Unit;
  public:
  void Shoot();
  void UpdateBullets(Suzu::Shader& shader);

  private:
  std::vector<Projectile> mBullets;
};
