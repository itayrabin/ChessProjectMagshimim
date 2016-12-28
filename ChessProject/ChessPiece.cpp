#include "ChessPiece.h"

ChessPiece::ChessPiece(bool isWhite, string type)
{
	_isWhite = isWhite;
	_type = type;
}


ChessPiece::~ChessPiece()
{

}

bool ChessPiece::isWhite() const
{
	return _isWhite;
}

string ChessPiece::getType() const
{
	return _type;
}
