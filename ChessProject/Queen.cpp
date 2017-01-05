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

vector<Location>* Queen::getMovePath(const Location& src, const Location& dest)
{
	int* difs = src.dif(dest);
	vector<Location>* locs = nullptr;
	int big = 0;
	int xChange = 0, yChange = 0;

	if (!(src.getY() == dest.getY() || src.getX() == dest.getX()) && (abs(difs[0]) != abs(difs[1])))
	{
		delete difs;
		return locs;
	}

	locs = new vector<Location>;

	big = abs((abs(difs[0]) > abs(difs[1]) ? abs(difs[0]) : abs(difs[1])));
	xChange = (difs[0] > 0 ? -1 : (difs[0] < 0 ? 1 : 0));
	yChange = (difs[1] > 0 ? -1 : (difs[1] < 0 ? 1 : 0));

	for (int i = 1; i <= big; i++)
	{
		locs->push_back(Location(src.getX() + (i * xChange), src.getY() + (i * yChange), nullptr));
	}

	delete difs;
	return locs;
}