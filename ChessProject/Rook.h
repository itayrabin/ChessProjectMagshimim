#ifndef ROOK_H
#define ROOK_H

#include <string>
#include <vector>
#include "Location.h"

using namespace std;

class Rook: public ChessPiece
{
public:
	Rook(bool isWhite);
	~Rook();
	virtual char createCharForString() const;
	virtual vector<Location>* getMovePath(const Location& source, const Location& dest) const;
private:
	
};

#endif