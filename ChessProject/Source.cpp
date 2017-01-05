#include "Pipe.h"
#include "Board.h"
#include <iostream>
#include <thread>

using namespace std;
void main()
{
	srand(time_t(NULL));
	system("start chessGraphics");
	Sleep(1500);
	
	Pipe p;
	bool isConnect = p.connect();
	
	string ans;
	while (!isConnect)
	{
		cout << "cant connect to graphics" << endl;
		cout << "Do you try to connect again or exit? (0-try again, 1-exit)" << endl;
		cin >> ans;

		if (ans == "0")
		{
			cout << "trying connect again.." << endl;
			Sleep(5000);
			isConnect = p.connect();
		}
		else 
		{
			p.close();
			return;
		}
	}
	

	
	// msgToGraphics should contain the board string accord the protocol
	// YOUR CODE
	Board board;
	
	p.sendMessageToGraphics(board.createStringForStart());   // send the board string

	// get message from graphics
	string msgFromGraphics = p.getMessageFromGraphics();
	char* response = new char[2];
	response[1] = '\0';

	Location* src;
	Location* dest;

	while (msgFromGraphics != "quit")
	{
		// should handle the string the sent from graphics
		// according the protocol. Ex: e2e4           (move e2 to e4)
		src = new Location(7 - (msgFromGraphics[1] - '1'), msgFromGraphics[0] - 'a', nullptr);
		dest = new Location(7 - (msgFromGraphics[3] - '1'), msgFromGraphics[2] - 'a', nullptr);
		response[0] = board.checkTurn(*src, *dest) + '0';
		//strcpy_s(msgToGraphics, "YOUR CODE"); // msgToGraphics should contain the result of the operation

		/******* JUST FOR EREZ DEBUGGING ******/
		//int r = rand() % 10; // just for debugging......
		//msgToGraphics[0] = (char)(1 + '0');
		//msgToGraphics[1] = 0;
		/******* JUST FOR EREZ DEBUGGING ******/


		// return result to graphics		
		p.sendMessageToGraphics(response);   

		// get message from graphics
		delete src;
		delete dest;
		msgFromGraphics = p.getMessageFromGraphics();
	}

	p.close();
}