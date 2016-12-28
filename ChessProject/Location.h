#ifndef LOCATION
#define LOCATION
#include "ChessPiece.h"

class ChessPiece;

class Location
{
public:
	Location(int x, int y, ChessPiece* pieceInLoc);
	~Location();

	int getX() const;
	int getY() const;
	ChessPiece* getPieceInLoc() const;
	int* dif(const Location& other) const;
	
	void setPieceInLoc(ChessPiece* piece);

private:
	int _x;
	int _y;
	ChessPiece* _pieceInLoc;
};

#endif