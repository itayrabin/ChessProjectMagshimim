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

vector<Location>* King::getMovePath(const Location& source, const Location& dest) const
{
	vector<Location>* rez = nullptr;
	int* dif = source.dif(dest);

	if (abs(dif[0]) <= 1 && abs(dif[1] <= 1))
	{
		rez = new vector<Location>;
		if (!(dif[0] == 0 && dif[1] == 0))
		{
			rez->push_back(dest);
		}
	}

	delete[] dif;
	return rez;
}

char King::createCharForString() const
{
	return (_isWhite ? 'K' : 'k');
}