#include "Rook.h"
#include <cmath>

Rook::Rook(bool isWhite) : ChessPiece(isWhite, "Rook")
{
	
}

Rook::~Rook()
{

}

/**
This function is creatig the char for the 
message string
input: none
output: R if white, r if black
*/
char Rook::createCharForString() const
{
	return (_isWhite ? 'R' : 'r');//checking if white
}

/**
This function is getting two locations and returns the path of the rook
to move between them
input: 
	const Location& soure - the source location
	const Location& dest - the destnation
output:
	empty vector if same location, null if cant move to that direction
*/
vector<Location>* Rook::getMovePath(const Location& source, const Location& dest) const
{
	vector<Location>* path = new vector<Location>;
	if (source.getX() == dest.getX() && source.getY() == dest.getY())//checking if in same place
	{
		return path;
	}
	else if (!(source.getY() == dest.getY() || source.getX() == dest.getX()))//cheking if cant move in that ocations
	{
		delete path;
		return nullptr;
	}

	if (source.getX() == dest.getX())//chekibng if moving left or right
	{
		if (source.getY() - dest.getY() < 0)//cheking if moving right
		{
			for (int i = 1; i <= abs(source.getY() - dest.getY()); i++)
			{
				path->push_back(Location(source.getX(), source.getY()+i, nullptr));//creating the path
			}
		}
		else//if not moving left
		{
			for (int i = 1; i <= abs(source.getY() - dest.getY()); i++)
			{
				path->push_back(Location(source.getX(), source.getY() - i, nullptr));//creating the path
			}
		}
	}
	else//moving up or down
	{
		if (source.getX() - dest.getX() > 0)//cheking if moving up
		{
			for (int i = 1; i <= source.getX() - dest.getX(); i++)
			{
				path->push_back(Location(source.getX() - i, source.getY(), nullptr));//creating the path
			}
		}
		else
		{
			for (int i = 1; i <= abs(source.getX() - dest.getX()); i++)//cheking if moving down
			{
				path->push_back(Location(source.getX() + i, source.getY(), nullptr));//creating the path
			}
		}
	}

	return path;
}