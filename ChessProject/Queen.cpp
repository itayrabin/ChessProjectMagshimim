#include "Queen.h"
#include <cmath>

Queen::Queen(bool isWhite) : ChessPiece(isWhite, "Queen")
{
}

Queen::~Queen()
{
}

char Queen::createCharForString() const
{
	return (_isWhite ? 'Q' : 'q');
}

vector<Location>* Queen::getMovePath(const Location& src, const Location& dest) const
{
	int* difs = src.dif(dest);
	vector<Location>* locs = nullptr;
	int big = 0;
	int xChange = 0, int yChange = 0;

	if ((difs[0] == 0 && difs[1] != 0) || (difs[0] != 0 && difs[1] == 0) || (difs[0] != difs[1])) //not a straight line
	{
		delete difs;
		return locs;
	}

	locs = new vector<Location>;

	big = abs((abs(difs[0]) > abs(difs[1]) ? abs(difs[0]) : abs(difs[1])));
	xChange = (difs[0] < 0 ? -1 : (difs[0] > 0 ? 1 : 0));
	yChange = (difs[1] < 0 ? -1 : (difs[1] > 0 ? 1 : 0));

	for (int i = 0; i < big; i++)
	{
		locs->push_back(Location(src.getX() + (i * xChange), src.getY() + (i * yChange), nullptr));
	}

	delete difs;
	return locs;
}