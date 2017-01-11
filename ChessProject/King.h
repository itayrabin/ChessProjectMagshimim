#ifndef KING_H
#define KING_H
#include "ChessPiece.h"

class King : public ChessPiece {
public:
	King( bool isWhite);
	~King();

	bool isInCheck() const;
	void setIsInCheck(bool isInCheck);
	virtual char createCharForString() const;
	virtual vector<Location>* getMovePath(const Location& source, const Location& dest);
	vector<Location>* getAllPossibleMoves(const Location& me);

private:
	bool _isInCheck;
};


#endif