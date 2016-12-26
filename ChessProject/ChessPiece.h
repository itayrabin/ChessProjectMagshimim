#ifndef CHESS_PIECE
#define CHESS_PIECE

#include <string>
#include "Location.h"
#include <vector>

using namespace std;
class ChessPiece
{
public:
	ChessPiece(bool isWhite, string type);
	virtual ~ChessPiece();
	virtual char createCharForString() const = 0;
	virtual vector<Location> getMovePath(const Location& source, const Location& dest) const = 0;
	bool isWhite();
	string getType();

private:
	string _type;

protected:
	bool _isWhite;
};
#endif