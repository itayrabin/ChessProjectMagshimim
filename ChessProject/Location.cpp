#include "Location.h"

Location::Location(int x, int y, ChessPiece* pieceInLoc)
{
	_x = x;
	_y = y;
	_pieceInLoc = pieceInLoc;
}

Location::~Location()
{
	if (_pieceInLoc != nullptr)
	{
		delete _pieceInLoc;
	}
}

int Location::getX() const
{
	return _x;
}

int Location::getY() const
{
	return _y;
}

ChessPiece* Location::getPieceInLoc() const
{
	return _pieceInLoc;
}

int* Location::dif(const Location& other) const
{
	int* rez = new int[2];
	rez[0] = _x - other._x;
	rez[1] = _y - other._y;

	return rez;
}