/*
 * Main.cpp
 *
 *  Created on: 12/01/2026
 *      Author: dongmo
 */

#include <ctime>
#include <iostream>

using namespace std;

#include "Board.h"
#include "Game.h"
#include "HumanPlayer.h"
#include "Player.h"

int main() {
	srand(time(0));
	int boardSize = 4;
	cout << "Input the size of board (>= 3):" << endl;
	cin >> boardSize;
	if (boardSize < 3)
		boardSize = 3;
	else if (boardSize > 15)
		boardSize = 15;

	Board *board = new Board(boardSize);

	cout << "Choose a player to play: " << endl;
	cout << "1. Human Player" << endl;
    //Add more option for different players 
	cout << "Others: Quit" << endl;

	int choice;
	cin >> choice;

	Player *p;

	if (choice == 1) {
		p = new HumanPlayer;
	} else {
		return 0;
	}



	Game game(board, p);

	cout << "Empty cells: " << board->countEmptyCells() << endl; // ALSO ADDED THIS IN GAME.PLAY()

	game.play();

	delete board;
	delete p;

	//	system("pause");
	return 0;
}
