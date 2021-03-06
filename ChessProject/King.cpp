#include "King.h"
#include <cmath>

/**
This function is creating a king object
input:
	bool isWhite - true if white false if black
*/
King::King(bool isWhite) : ChessPiece(isWhite, "King")
{
	_isInCheck = false;
}

King::~King()
{
}

/**
This function is returning if the function is in check
input:
	none
output:
	true if in check false otherwise
*/
bool King::isInCheck() const
{
	return _isInCheck;
}

/**
This function is setting _isInChcek
input:
	bool isInCheck - true or false
output:
	none
*/
void King::setIsInCheck(bool isInCheck)
{
	_isInCheck = isInCheck;
}

/**
This function is getting the move path for the king to the dest
input:
	const Location& source - the source of the move
	const Location& dest - the destenation of the move
output:
	vector of locations of the move path
*/
vector<Location>* King::getMovePath(const Location& source, const Location& dest)
{
	vector<Location>* rez = nullptr;
	int* dif = source.dif(dest); //get the offset between the src and dest

	if (abs(dif[0]) <= 1 && abs(dif[1]) <= 1) //if it's in range of king
	{
		rez = new vector<Location>; //create the vector
		if (!(dif[0] == 0 && dif[1] == 0)) //make sure it's not the same place
		{
			rez->push_back(dest);
		}
	}

	delete[] dif;
	return rez;
}


/**
This function is creating the char for the string 
input:
	none
output:
	K if white , k if black
*/
char King::createCharForString() const
{
	return (_isWhite ? 'K' : 'k');
}

/*
	this function creates a vector containing all of the places the
	king can move to
input-
	the current location of the king
output - 
	all the possible places the king can go, respecting board bounderies
*/

vector<Location>* King::getAllPossibleMoves(const Location& me)
{
	vector<Location>* posbs = new vector<Location>;
	if (me.getX() != 0)
	{
		posbs->push_back(Location(me.getX() - 1, me.getY(), nullptr));
		if (me.getY() != 0)
		{
			posbs->push_back(Location(me.getX() - 1, me.getY() - 1, nullptr));
		}

		if (me.getY() != 7)
		{
			posbs->push_back(Location(me.getX() - 1, me.getY() + 1, nullptr));
		}
	}

	if (me.getX() != 7)
	{
		posbs->push_back(Location(me.getX() + 1, me.getY(), nullptr));
		if (me.getY() != 0)
		{
			posbs->push_back(Location(me.getX() + 1, me.getY() - 1, nullptr));
		}

		if (me.getY() != 7)
		{
			posbs->push_back(Location(me.getX() + 1, me.getY() + 1, nullptr));
		}
	}

	if (me.getY() != 0)
	{
		posbs->push_back(Location(me.getX(), me.getY() - 1, nullptr));
	}

	if (me.getY() != 7)
	{
		posbs->push_back(Location(me.getX(), me.getY() + 1, nullptr));
	}

	return posbs;
}

