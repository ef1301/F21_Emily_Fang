#pragma once

#include "Suzu.h"
#include "Unit.h"

class Monster: public Unit {
  using Unit::Unit;
  public:
  void Move();
  void UpdateFacing(Unit::Direction newDir);
  void UpdatePosition() override;

  private:
  int mAngle = 0;
};
