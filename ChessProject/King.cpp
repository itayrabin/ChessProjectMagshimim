#include "King.h"
#include <cmath>

King::King(string type, bool isWhite) : ChessPiece(isWhite, type)
{
}

King::~King()
{
}

bool King::isInCheck() const
{
	return _isInCheck;
}

void King::setIsInCheck(bool isInCheck)
{
	_isInCheck = isInCheck;
}

vector<Location> King::getMovePath(const Location& source, const Location& dest) const
{
	Location** rez = nullptr;
	int difX = 0, difY = 0;

	difX = abs(source.getX() - dest.getX());
	difY = abs()

	if (source.getX() + 1 == dest.getX()) //move king 1 step to the right
	{
		if (source.getY() == dest.getY() || source.getY() + 1 == source.getX() || source.getY() - 1 == source.getX()) //all good with the rows
		{
			rez = new Location*[2];
			rez[0] = new Location(dest.getX(), dest.getY(), nullptr);
			rez[1] = nullptr;
		}
	}

	else if (source.getX() - 1 == dest.getX()) //1 to the left
	{
		if (source.getY() == dest.getY() || source.getY() + 1 == source.getX() || source.getY() - 1 == source.getX()) //all good with the rows
		{
			rez = new Location*[2];
			rez[0] = new Location(dest.getX(), dest.getY(), nullptr);
			rez[1] = nullptr;
		}
	}
}

char King::createCharForString() const
{
	return (_isWhite ? 'K' : 'k');
}