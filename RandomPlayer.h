/*
 * HumanPlayer.h
 *
 *  Created on: 12/01/2026
 *      Author: dongmo
 */

#ifndef RANDOMPLAYER_H_
#define RANDOMPLAYER_H_

using namespace std;

#include "Board.h"
#include "Player.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>


class RandomPlayer: public Player {
public:
	RandomPlayer() {
		name = "Random Player";
	}
	char getMove(const Board&);
};

char RandomPlayer::getMove(const Board& board) {
	char move = '*';
	vector<char> directions = {'u', 'd', 'r', 'l'};
	cout << "Randomly making a move.\n";
	int randNum = rand() % directions.size();
	move = directions[randNum];
	return move;
}

#endif /* HUMANPLAYER_H_ */
