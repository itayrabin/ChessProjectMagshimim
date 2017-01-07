#include "ChessPiece.h"
#ifndef PAWN
#define PAWN
class Pawn : public ChessPiece
{
public:
	Pawn(bool isWhite);
	~Pawn();
	virtual char createCharForString() const;
	virtual vector<Location>* getMovePath(const Location& src, const Location& dest);

private:
	bool _isFirstStep;
	bool checkNum(int toCheck, int lim);
};

#endif
