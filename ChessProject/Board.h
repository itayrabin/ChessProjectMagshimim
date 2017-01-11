#ifndef BOARD
#define BOARD
#include "ChessPiece.h"
#include "Location.h"

#define GOOD_MOVE 0
#define GOOD_MOVE_CHECK 1
#define BAD_MOVE_SRC 2
#define BAD_MOVE_DEST 3
#define BAD_MOVE_SELF_CHECK 4
#define BAD_MOVE_INDEX 5
#define BAD_MOVE_PIECE 6
#define BAD_MOVE_SAME 7
#define CHECK_MATE 8

#define BOARD_SIZE 8

class Board
{
public:
	Board();
	~Board();

	int checkTurn(const Location& source, Location& dest);
	char* createStringForStart();

private:
	ChessPiece*** _board;
	bool _isWhiteTurn;
	Location* _cache1;
	Location* _cache2;

	void createBoard();
	int checkCanMove(const Location& src, const Location& dest);
	Location* checkCheck(Location* king);
	void revertMove();
	Location* findKing(bool isWhite);
	void move(const Location& src, const Location& dest);
	bool checkMate(bool _isWhiteTurn);
};

#endif