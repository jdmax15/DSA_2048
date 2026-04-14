#ifndef SMARTPLAYERCOMBINATION_H_
#define SMARTPLAYERCOMBINATION_H_

using namespace std;

#include "Board.h"
#include "Player.h"
#include <iostream>
#include <cstdlib>
#include <queue>
#include <vector>

class SmartPlayerCombination: public Player {
	public:
        SmartPlayerCombination() {
            name = "Smart Combination Player";
        }
        char getMove(const Board&);
};

char SmartPlayerCombination::getMove(const Board& board) {

    vector<char> directions = {'u', 'd', 'l', 'r'};
    char bestMove = directions[0];
    int bestScore = -1;

    for (int i = 0; i < directions.size(); i++) {
        Board b1(board);
        b1.makeMove(directions[i]);

        if (board.countEmptyCells() == 0 &&
            b1.getCurrentScore() == board.getCurrentScore() &&
            b1.countEmptyCells() == board.countEmptyCells()) continue;

        b1.addNewTile();

        for (int j = 0; j < directions.size(); j++) {
            Board b2(b1);
            b2.makeMove(directions[j]);
            b2.addNewTile();

            for (int k = 0; k < directions.size(); k++) {
                Board b3(b2);
                b3.makeMove(directions[k]);
                b3.addNewTile();

                for (int l = 0; l < directions.size(); l++) {
                    Board b4(b3);
                    b4.makeMove(directions[l]);
                    b4.addNewTile();

                    if (b4.heuristic2() > bestScore) {
                    bestScore = b4.heuristic2();
                    bestMove = directions[i];




                }
            }
        }
    }

}

    return bestMove;

};

#endif
