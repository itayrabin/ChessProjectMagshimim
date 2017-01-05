#ifndef BISHOP_H
#define BISHOP_H
#include "ChessPiece.h"

class Bishop : public ChessPiece {
public:
	Bishop(bool isWhite);
	~Bishop();

	virtual char createCharForString() const;
	virtual vector<Location>* getMovePath(const Location& source, const Location& dest);

private:
	bool _isInCheck;
};


#endif