#ifndef SMARTMONTECARLOPLAYER_H_
#define SMARTMONTECARLOPLAYER_H_

using namespace std;

#include "Board.h"
#include "Player.h"
#include <iostream>
#include <cstdlib>
#include <queue>
#include <vector>
#include "MonteCarloPlayer.h"



class SmartMonteCarloPlayer: public MonteCarloPlayer {
	public:
        SmartMonteCarloPlayer() {
            name = "SmartMonteCarloPlayer (Hueristic)";
        }
        double simulation(const Board&) override;
};



double MonteCarloPlayer::simulation(const Board& board) {
    int simulation_runs = 100;
    double total_score = 0.0;
    vector<char> directions = {'u', 'd', 'l', 'r'};

    for (int i = 0; i < simulation_runs; i++) {
        Board tempBoard(board);
        while (tempBoard.canMove() && !tempBoard.hasWon()) {
            int randNum = rand() % directions.size();
            tempBoard.makeMove(directions[randNum]);
            tempBoard.addNewTile();
        }
        total_score += tempBoard.getCurrentScore();
    }

    return total_score / simulation_runs;

};

#endif
