#ifndef BESTFIRSTPLAYER_H_
#define BESTFIRSTPLAYER_H_

using namespace std;

#include "Board.h"
#include "Player.h"
#include <iostream>
#include <cstdlib>
#include <queue>

struct Move {
    char direction;
    int heuristic;
    Move(char d, int h): direction(d), heuristic(h) {}
    bool operator<(const Move& m) const {
        return heuristic < m.heuristic;
    }
};

class BestFirstPlayer: public Player {
	BestFirstPlayer() {
		name = "Best First Player (Hueristic)";
	}
	char getMove(const Board&);
};

char Player::getMove(const Board& board) {

}

#endif
