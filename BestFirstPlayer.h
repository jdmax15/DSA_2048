#ifndef BESTFIRSTPLAYER_H_
#define BESTFIRSTPLAYER_H_

using namespace std;

#include "Board.h"
#include "Player.h"
#include <iostream>
#include <cstdlib>
#include <queue>
#include <vector>

struct BestMove {
    char direction;
    int heuristic;
    BestMove(char d, int h): direction(d), heuristic(h) {}
    bool operator<(const BestMove& m) const {
        return heuristic < m.heuristic;
    }
};

class BestFirstPlayer: public Player {
	public:
        BestFirstPlayer() {
            name = "Best First Player (Hueristic)";
        }
        char getMove(const Board&);
};

char BestFirstPlayer::getMove(const Board& board) {

    priority_queue<BestMove> moves;
    vector<char> directions = {'u', 'd', 'l', 'r'};
    for (int i = 0; i < directions.size(); i++) {
        Board tempBoard(board);
        if (tempBoard.canMove()) {
            tempBoard.makeMove(directions[i]);
            BestMove m((directions[i]), tempBoard.heuristic());
            moves.push(m);
        }
    }

    if (moves.size() > 0) {
        return moves.top().direction;
    } else {
        cout << "Can't make move.\n";
        return 'u';
    }

};

#endif
