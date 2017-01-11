#include "Knight.h"


Knight::Knight(bool isWhite) :ChessPiece(isWhite, "Knight")
{

}

Knight::~Knight()
{

}

char Knight::createCharForString() const
{
	return (!_isWhite ? 'n' : 'N');
}


vector<Location>* Knight::getMovePath(const Location& source, const Location& dest)
{
	int* arr = source.dif(dest);
	vector<Location>* path = new vector<Location>;
	if (source.getX() == dest.getX() && source.getY() == dest.getY())//checking if in same place
	{
		return path;
	}
	else if (abs(arr[0])+ abs(arr[1]) != 3)
	{
		delete path;
		return nullptr;
	}
	else if (abs(arr[0]) == 3 || abs(arr[1] == 3))
	{
		delete path;
		return nullptr;
	}
	else
	{
		path->push_back(dest);
	}

	delete arr;
	return path;
}