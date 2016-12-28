#include "Board.h"

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
				delete _board[i][j]; //deleting the memory allocated
			}
		}

		delete[] _board[i]; //deleting the memory allocated
	}

	delete[] _board; //deleting the memory allocated
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
	*_board = new ChessPiece*[BOARD_SIZE];
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		_board[i] = new ChessPiece*[BOARD_SIZE]; //intalizing the array
	}

	for (int i = 0; i < 2; i++)//adding black side
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			//TODO: add 2 lines of Rook
		}
	}

	for (int i = 2; i < BOARD_SIZE - 2; i++)//adding nulls for empty spaces
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			_board[i][j] = nullptr;
		}
	}

	for (int i = BOARD_SIZE - 2; i < BOARD_SIZE; i++) //adding white side
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			//TODO: add 2 lines of Rook
		}
	}
}
