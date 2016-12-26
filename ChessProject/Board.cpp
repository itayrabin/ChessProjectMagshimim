#include "Board.h"

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
	*_board = new ChessPiece*[BOARD_SIZE];
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		_board[i] = new ChessPiece*[BOARD_SIZE];
	}

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			//TODO: add 2 lines of Rook
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
			//TODO: add 2 lines of Rook
		}
	}
}
