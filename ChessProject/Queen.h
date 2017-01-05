#include "ChessPiece.h"
#ifndef QUEEN
#define QUEEN
class Queen : public ChessPiece {
public:
	Queen(bool isWhite);
	~Queen();
	virtual char createCharForString() const;
	vector<Location>* getMovePath(const Location& src, const Location& dest) const;
};

#endif