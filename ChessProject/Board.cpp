#include "Board.h"
#include "stdafx.h"

/**
This functions is creating a board object
input:
	none
*/
Board::Board()
{
	createBoard(); //calling to create board
	_isWhiteTurn = true;
	_cache1 = nullptr;
	_cache2 = nullptr;

}

/**
This function is deleting the memory allocated 
for board
input: none
*/
Board::~Board()
{
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			if (_board[i][j] != nullptr)
			{
				delete _board[i][j]; //deleting each ChessPiece
			}
		}

		delete[] _board[i]; //deleting the entire row
	}

	delete[] _board; //deleting the entire board
}

/**
This function is creating a board for the start of the program
input:
	none
output:
	none
*/
void Board::createBoard()
{
	_board = new ChessPiece**[BOARD_SIZE];
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		_board[i] = new ChessPiece*[BOARD_SIZE]; //intalizing the array
	}

	//for (int i = 0; i < 2; i++)//adding black side
	//{
	//	for (int j = 0; j < BOARD_SIZE; j++)
	//	{
	//		if (j == 3 && i == 0) //add 1 black king
	//		{
	//			_board[i][j] = new King(false);
	//
	//		}
	//		else
	//		{
	//			_board[i][j] = new Rook(false);
	//		}
	//	}
	//}
	//
	//for (int i = 2; i < BOARD_SIZE - 2; i++)//adding nulls for empty spaces
	//{
	//	for (int j = 0; j < BOARD_SIZE; j++)
	//	{
	//		_board[i][j] = nullptr;
	//	}
	//}
	//
	//for (int i = BOARD_SIZE - 2; i < BOARD_SIZE; i++) //adding white side
	//{
	//	for (int j = 0; j < BOARD_SIZE; j++)
	//	{
	//		if (j == 3 && i == BOARD_SIZE - 1) //add 1 white king
	//		{
	//			_board[i][j] = new King(true);
	//
	//		}
	//		else
	//		{
	//			_board[i][j] = new Rook(true);
	//		}
	//	}
	//}

	_board[0][0] = new Rook(false);
	_board[0][1] = new Knight(false);
	_board[0][2] = new Bishop(false);
	_board[0][3] = new Queen(false);
	_board[0][4] = new King(false);
	_board[0][5] = new Bishop(false);
	_board[0][6] = new Knight(false);
	_board[0][7] = new Rook(false);

	for (int i = 1; i < 7; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (i == 1 || i == 6)
				_board[i][j] = new Pawn(i == 1 ? false : true);
			else
				_board[i][j] = nullptr;
		}
	}

	_board[7][0] = new Rook(true);
	_board[7][1] = new Knight(true);
	_board[7][2] = new Bishop(true);
	_board[7][3] = new Queen(true);
	_board[7][4] = new King(true);
	_board[7][5] = new Bishop(true);
	_board[7][6] = new Knight(true);
	_board[7][7] = new Rook(true);
}

/*
This function is creating the string for the start to 
send to the frontend
input:
	none
output:
	char* - te string for the start

*/
char* Board::createStringForStart()
{
	char* msg = new char[66];
	int index = 0;
	for (int i = 0; i < BOARD_SIZE; i++)
	{	
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			if (_board[i][j] == nullptr)
			{
				msg[index++] = '#';//empty space is #
			}
			else
			{
				msg[index++] = _board[i][j]->createCharForString(); //getting the piece in the location
			}
		}
	}

	msg[index++] = '0';//adding who starts
	msg[index++] = '\0';//addin the end of string
	return msg;
}

/**
This function is chenging back the board using the two caches
input:
	none
output:
	none
*/
void Board::revertMove()
{
	_board[_cache1->getX()][_cache1->getY()] = _cache1->getPieceInLoc(); //returning cache1 to his place
	_board[_cache2->getX()][_cache2->getY()] = _cache2->getPieceInLoc();//returning cache2 to his place
}

/*
This function is moving the piece in the source to destnation, and putting an empty
place in the source

input:
	const Location& src - the source of the move
	const Location& dest - the move destenation
output:
	none
*/
void Board::move(const Location& src, const Location& dest)
{
	if (_cache1 != nullptr)//checking if there is cache1
	{
		//freeing the cache1
		_cache1->setPieceInLoc(nullptr); //dont free the ChessPiece it keeps
		delete _cache1;
		_cache1 = nullptr;
	}

	if (_cache2 != nullptr)
	{
		//freeing the cache2
		_cache2->setPieceInLoc(nullptr); //dont free the ChessPiece it keeps
		delete _cache2;
		_cache2 = nullptr;
	}


	//adding the new move to cache
	_cache1 = new Location(src.getX(), src.getY(), _board[src.getX()][src.getY()]);
	_cache2 = new Location(dest.getX(), dest.getY(), _board[dest.getX()][dest.getY()]);

	//moving the src to dest and replacing source as empty place
	_board[dest.getX()][dest.getY()] = _board[src.getX()][src.getY()];
	_board[src.getX()][src.getY()] = nullptr;

}

/**
this function checking if a check was made

input:
	Location* king - the location of the king to do the check on
output:
	true if check was made false otherwise
*/
bool Board::checkCheck(Location* king)
{
	Location* src = nullptr;
	for (int i = 0; i < BOARD_SIZE; i++)//going on all the board
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			if (_board[i][j] != nullptr && _board[i][j]->isWhite() != king->getPieceInLoc()->isWhite()) //getting the enemy piece
			{
				if (checkCanMove(*(src = new Location(i, j, _board[i][j])), *king) == GOOD_MOVE)//cheking if the king can be eaten by enemy piece
				{
					//if yes returning true
					src->setPieceInLoc(nullptr);
					delete src;
					return true;
				}

				src->setPieceInLoc(nullptr);
				delete src;
			}
		}
	}

	return false;//if no check found, returning false
}

/**
This function is checking the turn for valid move and returnon the current code
input:
	const Location& source - the source to move from
	const Location& dest - the destenation to move to
output:
	te move code (see board.h defines)

*/
int Board::checkTurn(const Location& source, const Location& dest)
{
	//checking if the index is valid
	if (source.getX() > 7 || source.getY() > 7 || dest.getX() > 7 || dest.getY() > 7
		|| source.getX() < 0 || source.getY() < 0 || dest.getX() < 0 || dest.getY() < 0)
	{
		return BAD_MOVE_INDEX;
	}

	//cheking if theres nothing to move in that place or the piece is not yours
	if (_board[source.getX()][source.getY()] == nullptr || _board[source.getX()][source.getY()]->isWhite() != _isWhiteTurn)
	{
		return BAD_MOVE_SRC;
	}

	//cheking if there is same player as move player in the source
	if (_board[dest.getX()][dest.getY()] != nullptr && _board[dest.getX()][dest.getY()]->isWhite() == _isWhiteTurn)
	{
		return BAD_MOVE_DEST;
	}

	int rez = checkCanMove(source, dest);//checking if a valid move for the piece

	if (rez != GOOD_MOVE) //checkCanMove checks for piece's path and if the src and dest are the same
	{
		return rez;//retuning error if there is
	}
	
	move(source, dest);//moving the piece

	//check Self Check
	Location* king = findKing(_isWhiteTurn);
	bool isInCheck = checkCheck(king);
	if (isInCheck)
	{
		//if there is self check reverting the move and returning the error code
		revertMove(); 
		king->setPieceInLoc(NULL);
		delete king;
		return BAD_MOVE_SELF_CHECK;
	}

	delete _cache2->getPieceInLoc();//deleting the cache if no need to revert

	//cheking for check on the enemy
	king = findKing(!_isWhiteTurn);
	isInCheck = checkCheck(king);
	if (isInCheck)
	{
		//if made a check returning the code
		king->setPieceInLoc(NULL);
		delete king;
		_isWhiteTurn = !_isWhiteTurn;
		return GOOD_MOVE_CHECK;
	}
	

	king->setPieceInLoc(NULL);
	delete king;
	_isWhiteTurn = !_isWhiteTurn;//changing the turn
	return GOOD_MOVE;//returning good move 
}

/**
This function if a specific piece can move from 
source to dest 

input:
	const Location& source - the source to move from
	const Location& dest - the destenation to move to
output:

	the move code
*/
int Board::checkCanMove(const Location& source, const Location& dest)
{
	vector<Location>* v = _board[source.getX()][source.getY()]->getMovePath(source, dest); //getting the answer from getMovePath
	if (v == nullptr)//if null the piece cant do that move
	{
		return BAD_MOVE_PIECE;
	}

	if (v->size() == 0) // if size == 0 , src and dest are the same
	{
		return BAD_MOVE_SAME;
	}

	for (int i = 0; i < v->size() - 1; i++)
	{
		if (_board[v->at(i).getX()][v->at(i).getY()] != nullptr)
		{
			return BAD_MOVE_PIECE; //cheking for a piece in the way
		}
	}

	return GOOD_MOVE;
}

/**
This function is finding and returning the location of 
the king 
input:
	iswhite - white or black
output:
	the king Location
*/
Location* Board::findKing(bool isWhite)
{
	for (int i = 0; i < BOARD_SIZE; i++)//going on all the board
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			if (_board[i][j] != nullptr && _board[i][j]->getType() == "King" && _board[i][j]->isWhite() == isWhite)//cheking if its the king
			{
				return new Location(i, j, _board[i][j]);//returning the location
			}
		}
	}

	return NULL;//if not found returnng null
}



