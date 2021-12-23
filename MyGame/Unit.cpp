#include "Unit.h"

Unit::Unit(const std::string& imageFile, int xPos, int yPos, int speed)
	: mPosX(xPos), mPosY(yPos), 
	mSpeed(speed), 
	mDirection(Direction::Left)
{
	mImage.LoadImage(imageFile);
}

Unit::Unit(const std::string& imageFile, int xPos, int yPos)
	: mPosX(xPos), mPosY(yPos), 
	mSpeed(0), 
	mDirection(Direction::None)
{
	mImage.LoadImage(imageFile);
}

int Unit::GetUnitWidth() const
{
	return mImage.GetWidth();
}

int Unit::GetUnitHeight() const
{
	return mImage.GetHeight();
}

void Unit::SetPosX(int newX)
{
	mPosX = newX;
}

void Unit::SetPosY(int newY)
{
	mPosY = newY;
}

int Unit::GetPosX() const
{
	return mPosX;
}

int Unit::GetPosY() const
{
	return mPosY;
}

int Unit::GetSpeed() const
{
	return mSpeed;
}

Unit::Direction Unit::GetDirection() const
{
	return mDirection;
}

void Unit::SetDirection(Unit::Direction newDirection)
{
	mDirection = newDirection;
}

Unit::Direction Unit::GetFacing() const
{
	return mFacing;
}

void Unit::UpdateFacing()
{
  if(mDirection == Unit::Direction::Left) mFacing = mDirection;
  if(mDirection == Unit::Direction:: Right) mFacing = mDirection;
}

void Unit::UpdatePosition()
{
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
		break;
	}
  UpdateFacing();
}

bool Unit::CollideWith(const Unit& other) const
{
	int oXleft{ other.GetPosX() };
	int oXright{ other.GetPosX() + other.GetUnitWidth() };
	int oYbottom{ other.GetPosY() };
	int oYtop{ other.GetPosY() + other.GetUnitHeight() };

	bool intersectOnX{ 
		(mPosX <= oXleft && oXleft <= mPosX + GetUnitWidth()) ||
		(mPosX <= oXright && oXright <= mPosX + GetUnitWidth()) ||
		(oXleft <= mPosX && mPosX + GetUnitWidth() <= oXright)
		};

	bool intersectOnY{
		(mPosY <= oYbottom && oYbottom <= mPosY + GetUnitHeight()) ||
		(mPosY <= oYtop && oYtop <= mPosY + GetUnitHeight()) ||
		(oYbottom <= mPosY && mPosY + GetUnitHeight() <= oYtop)

	};

	return intersectOnX && intersectOnY;
}

bool Unit::IsPositionPossible(int newX, int newY) const
{
	if (newX < 0 || newY < 0 || 
		(newX + mImage.GetWidth() > 1200) || 
		(newY + mImage.GetHeight() > 800)) 
		return false;
	else 
		return true;
}

bool Unit::IsAtEdge() const
{
  	if (mPosX <= 0 || mPosY <= 0 || 
		(mPosX + mImage.GetWidth() >= 1200) || 
		(mPosY + mImage.GetHeight() >= 800)) 
		return true;
    else {
      return false;
    }
}

void Unit::Draw(Suzu::Shader& shader)
{
	Suzu::Renderer::Draw(mImage, mPosX, mPosY, mImage.GetWidth(), mImage.GetHeight(), shader);
}
