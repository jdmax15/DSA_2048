#ifndef BESTFIRSTPLAYER_H_
#define BESTFIRSTPLAYER_H_

using namespace std;

#include "Board.h"
#include "Player.h"
#include <iostream>
#include <cstdlib>

class BestFirstPlayer: public Player {
	BestFirstPlayer() {
		name = "Best First Player (Hueristic)";
	}
	char getMove(const Board&);
};

char Player::getMove(const Board& board) {

}

#endif
