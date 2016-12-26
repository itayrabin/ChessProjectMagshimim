#include "ChessPiece.h"


ChessPiece::ChessPiece(bool isWhite, string type)
{
	_isWhite = isWhite;
	_type = type;
}


ChessPiece::~ChessPiece()
{

}

bool ChessPiece::isWhite()
{
	return _isWhite;
}

string ChessPiece::getType()
{
	return _type;
}
