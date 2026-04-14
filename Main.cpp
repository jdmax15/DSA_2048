#include <ctime>
#include <iostream>

using namespace std;

#include "Board.h"
#include "Game.h"
#include "SmartPlayerCombination.h"
#include "MonteCarloPlayer.h"
#include "SmartPlayer.h"
#include "SmartPlayer2.h"
#include "HumanPlayer.h"
#include "RandomPlayer.h"
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
    cout << "2. Random Player" << endl;
	cout << "3. Smart Player (Best Score Heuristic)" << endl;
	cout << "4. Smart Player 2 (Looks ahead 2 levels deep)" << endl;
	cout << "5. Monte Carlo Player" << endl;
	cout << "6. Smart Player Combination (Multiple heuristics + 4 level look ahead)" << endl;
	cout << "Others: Quit" << endl;

	int choice;
	cin >> choice;

	Player *p;

	if (choice == 1) {
		p = new HumanPlayer;
	} 
	else if (choice == 2) {
		p = new RandomPlayer;	
	}
	else if (choice == 3) {
		p = new SmartPlayer;
	}
	else if (choice == 4) {
		p = new SmartPlayer2;
	}
	else if (choice == 5) {
		int runs, depth;
		bool scores;
		cout << "Enter number of simulations: " << endl;
		cin >> runs;
		cout << "Enter max depth (0 for unlimited): " << endl;
		cin >> depth;
		cout << "Print simulation scores each move? 1 for yes, 0 for no " << endl;
		cin >> scores;
		p = new MonteCarloPlayer(runs, depth, scores);
	}
	else if (choice == 6) {
		p = new SmartPlayerCombination;
	}
	else {
		return 0;
	}



	Game game(board, p);

	cout << "Empty cells: " << board->countEmptyCells() << endl;

	game.play();

	return 0;
}
