#include "Bishop.h"
#include <cmath>


Bishop::Bishop(bool isWhite) :ChessPiece(isWhite, "Bishop")
{
}


Bishop::~Bishop()
{

}


char Bishop::createCharForString() const
{
	return (_isWhite ? 'B' : 'b');
}


vector<Location>* Bishop::getMovePath(const Location& source, const Location& dest) const
{
	int* arr = source.dif(dest);
	int two = 0;
	int one = 0;
	vector<Location>* path = new vector<Location>;
	if (source.getX() == dest.getX() && source.getY() == dest.getY())//checking if in same place
	{
		return path;
	}
	else if (abs(arr[0]) != abs(arr[1]))
	{
		return nullptr;
	}
	else
	{
		if (arr[0] > 0 && arr[1] < 0)
		{
			one = -1;
			two = 1;
		}
		else if (arr[0] > 0 && arr[1] > 0)
		{
			one = -1;
			two = -1;
		}
		else if (arr[0] < 0 && arr[1] <0 )
		{
			one = 1;
			two = 1;
		}
		else
		{
			one = 1;
			two = -1;
		}

			
		for (int i = 1; i <= arr[0]; i++)
		{
			path->push_back(Location(source.getX() + i*one, source.getY()+i*two, nullptr));//creating the path
		}
	}

	delete arr;
	return path;
}