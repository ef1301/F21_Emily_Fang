#pragma once

#include "Suzu.h"
#include "Unit.h"

class Projectile: public Unit {
  using Unit::Unit;
  public:
  Projectile() = delete;
  void UpdatePosition() override;
};
