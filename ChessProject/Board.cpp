#include "Board.h"
#include "stdafx.h"

Board::Board()
{
	createBoard();
	_isWhiteTurn = true;
	_cache1 = nullptr;
	_cache2 = nullptr;

}

Board::~Board()
{
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			if (_board[i][j] != nullptr)
			{
				delete _board[i][j];
			}
		}

		delete[] _board[i];
	}

	delete[] _board;
}

void Board::createBoard()
{
	_board = new ChessPiece**[BOARD_SIZE];
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		_board[i] = new ChessPiece*[BOARD_SIZE];
	}

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			if (j == 3 || j == 4)
			{
				_board[i][j] = new King(false);

			}
			else
			{
				_board[i][j] = new Rook(false);
			}
		}
	}

	for (int i = 2; i < BOARD_SIZE - 2; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			_board[i][j] = nullptr;
		}
	}

	for (int i = BOARD_SIZE - 2; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			if (j == 3 || j == 4)
			{
				_board[i][j] = new King(true);

			}
			else
			{
				_board[i][j] = new Rook(true);
			}
		}
	}
}

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
				msg[index++] = '#';
			}
			else
			{
				msg[index++] = _board[i][j]->createCharForString();
			}
		}
	}

	msg[index++] = '0';
	msg[index++] = '\0';
	return msg;
}

void Board::revertMove()
{
	_board[_cache1->getX()][_cache1->getY()] = _cache1->getPieceInLoc();
	_board[_cache2->getX()][_cache2->getY()] = _cache2->getPieceInLoc();
}


void Board::move(const Location& src, const Location& dest)
{
	if (_cache1 != nullptr)
	{
		_cache1->setPieceInLoc(nullptr);
		delete _cache1;
		_cache1 = nullptr;
	}

	if (_cache2 != nullptr)
	{
		_cache2->setPieceInLoc(nullptr);
		delete _cache2;
		_cache2 = nullptr;
	}


	//TODO add to cache
	_cache1 = new Location(src.getX(), src.getY(), _board[src.getX()][src.getY()]);
	_cache2 = new Location(dest.getX(), dest.getY(), _board[dest.getX()][dest.getY()]);


	_board[dest.getX()][dest.getY()] = _board[src.getX()][src.getY()];
	_board[src.getX()][src.getY()] = nullptr;

}

bool Board::checkCheck(Location* king)
{
	Location* src = nullptr;
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			if (_board[i][j] != nullptr && _board[i][j]->isWhite() != king->getPieceInLoc()->isWhite())
			{
				if (checkCanMove(*(src = new Location(i, j, _board[i][j])), *king) == GOOD_MOVE)
				{
					src->setPieceInLoc(nullptr);
					delete src;
					return true;
				}

				src->setPieceInLoc(nullptr);
				delete src;
			}
		}
	}

	return false;
}

int Board::checkTurn(const Location& source, const Location& dest)
{
	if (source.getX() > 7 || source.getY() > 7 || dest.getX() > 7 || dest.getY() > 7
		|| source.getX() < 0 || source.getY() < 0 || dest.getX() < 0 || dest.getY() < 0)
	{
		return BAD_MOVE_INDEX;
	}

	if (_board[source.getX()][source.getY()] == nullptr || _board[source.getX()][source.getY()]->isWhite() != _isWhiteTurn)
	{
		return BAD_MOVE_SRC;
	}

	if (_board[dest.getX()][dest.getY()] != nullptr && _board[dest.getX()][dest.getY()]->isWhite() == _isWhiteTurn)
	{
		return BAD_MOVE_DEST;
	}

	int rez = checkCanMove(source, dest);
	if (rez != GOOD_MOVE)
	{
		return rez;
	}
	
	move(source, dest);
	//check Self Check
	Location* king = findKing(_isWhiteTurn);
	bool isInCheck = checkCheck(king);
	if (isInCheck)
	{
		revertMove();
		king->setPieceInLoc(NULL);
		delete king;
		return BAD_MOVE_SELF_CHECK;
	}

	delete _cache2->getPieceInLoc();

	king = findKing(!_isWhiteTurn);
	isInCheck = checkCheck(king);
	if (isInCheck)
	{
		king->setPieceInLoc(NULL);
		delete king;
		_isWhiteTurn = !_isWhiteTurn;
		return GOOD_MOVE_CHECK;
	}
	
	king->setPieceInLoc(NULL);
	delete king;
	_isWhiteTurn = !_isWhiteTurn;
	return GOOD_MOVE;
}

int Board::checkCanMove(const Location& source, const Location& dest)
{
	vector<Location>* v = _board[source.getX()][source.getY()]->getMovePath(source, dest);
	if (v == nullptr)
	{
		return BAD_MOVE_PIECE;
	}

	if (v->size() == 0)
	{
		return BAD_MOVE_SAME;
	}

	for (int i = 0; i < v->size() - 1; i++)
	{
		if (_board[v->at(i).getX()][v->at(i).getY()] != nullptr)
		{
			return BAD_MOVE_PIECE;
		}
	}

	return GOOD_MOVE;
}

Location* Board::findKing(bool isWhite)
{
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			if (_board[i][j] != nullptr && _board[i][j]->getType() == "King" && _board[i][j]->isWhite() == isWhite)
			{
				return new Location(i, j, _board[i][j]);
			}
		}
	}

	return NULL;
}



