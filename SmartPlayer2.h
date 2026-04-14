#ifndef SMARTPLAYER2_H_
#define SMARTPLAYER2_H_

using namespace std;

#include "Board.h"
#include "Player.h"
#include <iostream>
#include <cstdlib>
#include <queue>
#include <vector>
#include "SmartPlayer.h"

class SmartPlayer2: public Player {
	public:
        SmartPlayer2() {
            name = "Best First Player 2 (Looks ahead 2 levels deep)";
        }
        char getMove(const Board&);
};

char SmartPlayer2::getMove(const Board& board) {

    vector<char> directions = {'u', 'd', 'l', 'r'};
    char bestMove = directions[0];
    int bestScore = -1;

    for (int i = 0; i < directions.size(); i++) {
        Board b1(board);
        b1.makeMove(directions[i]);

        if (board.countEmptyCells() == 0 &&
            b1.getCurrentScore() == board.getCurrentScore() &&
            b1.countEmptyCells() == board.countEmptyCells()) continue;

        for (int j = 0; j < directions.size(); j++) {
            Board b2(b1);
            b2.makeMove(directions[j]);
            if (b2.heuristic() > bestScore) {
                bestScore = b2.heuristic();
                bestMove = directions[i];
            }
        }
    }

    return bestMove;

};

#endif
