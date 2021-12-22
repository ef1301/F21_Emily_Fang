#pragma once

#include "Suzu.h"
#include "Unit.h"

class Monster: public Unit {
  using Unit::Unit;
  public:
  void Move();
  void UpdatePosition() override;
};
