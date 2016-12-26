#ifndef CHESS_PIECE
#define CHESS_PIECE

#include <string>
#include "Location.h"

using namespace std;
class ChessPiece
{
public:
	ChessPiece(bool isWhite, string type);
	virtual ~ChessPiece();
	virtual char createCharForString() const = 0;
	virtual Location* getMovePath(const Location& source, const Location& dest) const = 0;
	bool isWhite();
	string getType();
private:
	bool _isWhite;
	string _type;

};
#endif