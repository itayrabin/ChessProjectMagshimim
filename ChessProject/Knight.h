#ifndef KNIGHT_H
#define KNIGHT_H

#include <string>
#include <vector>
#include "Location.h"

using namespace std;

class Knight : public ChessPiece
{
public:
	Knight(bool isWhite);
	~Knight();
	virtual char createCharForString() const;
	virtual vector<Location>* getMovePath(const Location& source, const Location& dest) const;

};

#endif