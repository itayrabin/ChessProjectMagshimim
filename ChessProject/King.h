#ifndef KING.H
#define KING.H
#include "ChessPiece.h"

class King : public ChessPiece {
public:
	King(string type, bool isWhite);
	~King();

	bool isInCheck() const;
	void setIsInCheck(bool isInCheck);
	virtual char createCharForString() const;
	virtual vector<Location> getMovePath(const Location& source, const Location& dest) const;

private:
	bool _isInCheck;
};


#endif