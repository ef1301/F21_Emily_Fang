#pragma once

#include "Suzu.h"

class Unit
{
public:
	Unit() = delete;
	Unit(const std::string & imageFile, 
		int xPos, int yPos, int speed);
	Unit(const std::string & imageFile, 
		int xPos, int yPos);
	int GetUnitWidth() const;
	int GetUnitHeight() const;
	void SetPosX(int newX);
	void SetPosY(int newY);
	int GetPosX() const;
	int GetPosY() const;
	int GetSpeed() const;

	enum class Direction {
		None,
		Up,
		Down,
		Left,
		Right
	};

	Unit::Direction GetDirection() const;
	void SetDirection(Unit::Direction newDirection);
	Unit::Direction GetFacing() const;
	void UpdateFacing();
	virtual void UpdatePosition();
  

	// CollideWith returns true if this unit and other unit will collide (overlap)
	bool CollideWith(const Unit& other) const;
  bool IsAtEdge() const;

	void Draw(Suzu::Shader & shader);
protected:
	bool IsPositionPossible(int newX, int newY) const;

	Suzu::Sprite mImage;
	int mPosX;
	int mPosY;
	int mSpeed;

	Direction mDirection;
  Direction mFacing;
};

