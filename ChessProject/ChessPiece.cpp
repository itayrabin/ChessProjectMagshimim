#include "ChessPiece.h"

/**
This function is creating a chessPiece object
input:
	bool isWhite - true if white, false if black
	string type - the piece type
*/
ChessPiece::ChessPiece(bool isWhite, string type)
{
	_isWhite = isWhite;
	_type = type;
}


ChessPiece::~ChessPiece()
{

}

/**
This function is returning if the Piece is black or white
input:
	none	
output:
	true if white false 
*/
bool ChessPiece::isWhite() const
{
	return _isWhite;
}

/**
This function is getting the type of the piece
input:
	none
output:
	the piece type
*/
string ChessPiece::getType() const
{
	return _type;
}
