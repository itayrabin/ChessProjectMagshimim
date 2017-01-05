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
		return new vector < Location > ;
	}

	if (checkNum(difs[0], 2, false))
	{
		delete difs;
		return locs;
	}

	if (checkNum(difs[1], 1, false))
	{
		delete difs;
		return locs;
	}


	if (checkNum(difs[1], 1, true) && checkNum(difs[0], 1, true) && dest.getPieceInLoc() != nullptr && !(dest.getPieceInLoc()->isWhite()))
	{
		locs = new vector<Location>();
		locs->push_back(dest);
		delete difs;
		return locs;
	}


	if (checkNum(difs[0], 2, true) && _isFirstStep)
	{

		locs = new vector<Location>();
		locs->push_back(Location(src.getX() - (difs[0] / 2), src.getY(), nullptr));
		locs->push_back(dest);
		delete difs;
		return locs;
	}

	if (checkNum(difs[0], 1, true) && !checkNum(difs[1], 1, true))
	{
		locs = new vector<Location>();
		locs->push_back(dest);
	}

	_isFirstStep = false;
	delete difs;
	return locs;
}

bool Pawn::checkNum(int toCheck, int lim, bool equel)
{
	if (_isWhite)
	{
		if (equel)
		{
			return toCheck == lim;
		}

		else
		{
			return toCheck > lim;
		}
	}
	
	else
	{
		if (equel)
			return -toCheck == lim;
		else
			return (toCheck < -lim);
	}
}
