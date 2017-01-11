#include "Pawn.h"
#include <cmath>

Pawn::Pawn(bool isWhite) : ChessPiece(isWhite, "Pawn")
{
	_isFirstStep = true;
}

Pawn::~Pawn()
{
}

char Pawn::createCharForString() const
{
	return (_isWhite ? 'P' : 'p');
}

vector<Location>* Pawn::getMovePath(const Location& src, const Location& dest)
{
	int* difs = src.dif(dest);
	vector<Location>* locs = nullptr;

	if (difs[0] == 0 && difs[1] == 0)
	{
		locs = new vector<Location>;
	}

	else if (dest.getPieceInLoc() != nullptr) //there is an enemy in the dest
	{
		if (checkNum(difs[0], 1) && abs(difs[1]) == 1) //moves diagonally to eat someone
		{
			locs = new vector<Location>; //create the path
			locs->push_back(dest);
		}
	}

	else if (difs[1] == 0) //move only forward
	{
		if (checkNum(difs[0], 1)) //moves only 1 forward
		{
			locs = new vector<Location>;
			locs->push_back(dest);
		}

		else if (checkNum(difs[0], 2) && _isFirstStep) //move 2 forward
		{
			locs = new vector<Location>;
			locs->push_back(Location(src.getX() - difs[0] / 2, src.getY(), nullptr));
			locs->push_back(dest);
		}
	}

	if (locs != nullptr && locs->size()) //only change this if the move was legal
		_isFirstStep = false;
	
	delete difs;
	return locs;
}

bool Pawn::checkNum(int toCheck, int lim) //cant simply use abs because pawn only goes forward
{
	if (_isWhite)
		return toCheck == lim;
	
	else
		return -toCheck == lim;
}
