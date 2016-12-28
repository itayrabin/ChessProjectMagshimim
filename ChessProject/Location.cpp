#include "Location.h"

/**
This function is creating a location object 
input:
	int x,y - the location in the board
	pieceInLoce - the piece in that location
*/
Location::Location(int x, int y, ChessPiece* pieceInLoc)
{
	_x = x;
	_y = y;
	_pieceInLoc = pieceInLoc;
}

/**
This function is deleting the memory
allocated for location

*/
Location::~Location()
{
	if (_pieceInLoc != nullptr)
	{
		delete _pieceInLoc;
	}
}

/**
This function is returning x
input:
	none	
output:
	int x
*/
int Location::getX() const
{
	return _x;
}

/**
This function is returning x
input:
none
output:
int y
*/
int Location::getY() const
{
	return _y;
}

/**
This function is returning the piece in the location
input:
none
output:
	ChessPiece piececInloc
*/
ChessPiece* Location::getPieceInLoc() const
{
	return _pieceInLoc;
}

/*
This function is returning the difrence between two locations

input:
	the other location
output
 rez[0] - the diffrence between the x's
 rez[1] - the diffrence between the y's
*/
int* Location::dif(const Location& other) const
{
	int* rez = new int[2];
	rez[0] = _x - other._x;
	rez[1] = _y - other._y;

	return rez;
}

/**
This function is setting thepieceInLoc
input:
	ChessPiece* piece - THE PIECE TO SET
output:
None
*/
void Location::setPieceInLoc(ChessPiece* piece)
{
	_pieceInLoc = piece;
}