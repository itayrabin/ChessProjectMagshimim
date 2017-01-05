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

	if (difs[1] < -2)
	{
		delete difs;
		return locs;
	}

	if (difs[0] < -1)
	{
		delete difs;
		return locs;
	}

	if (difs[0] == -1 && difs[1] == -1 && dest.getPieceInLoc() != nullptr && !(dest.getPieceInLoc()->isWhite()))
	{
		locs->push_back(dest);
		delete difs;
		return locs;
	}

	if (difs[1] == -2 && _isFirstStep)
	{
		locs->push_back(Location(src.getX(), src.getY() + (difs[1] / 2), nullptr));
		locs->push_back(dest);
		_isFirstStep = false;
		delete difs;
		return locs;
	}

	if (difs[1] == -1)
	{
		locs->push_back(dest);
	}

	delete difs;
	return locs;
}
