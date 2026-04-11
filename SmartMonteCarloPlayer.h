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



double SmartMonteCarloPlayer::simulation(const Board& board) {
    int simulation_runs = 200;
    int max_depth = 50;

    double total_score = 0.0;
    vector<char> directions = {'u', 'd', 'l', 'r'};

    for (int i = 0; i < simulation_runs; i++) {
        Board tempBoard(board);
        int steps = 0;

        while (tempBoard.canMove() && !tempBoard.hasWon() && steps < max_depth) {
            char bestMove = directions[0];
            int bestHeuristic = -1;

            for (int j = 0; j < directions.size(); j++) {
                Board trial(tempBoard);
                trial.makeMove(directions[j]);

            if (trial.getCurrentScore() == tempBoard.getCurrentScore() &&
                trial.countEmptyCells() == tempBoard.countEmptyCells()) continue;

                if (trial.heuristic2() > bestHeuristic) {
                    bestHeuristic = trial.heuristic2();
                    bestMove = directions[j];
                }
            }
            tempBoard.makeMove(bestMove);
            tempBoard.addNewTile();
            steps++;
        }
        total_score += tempBoard.getCurrentScore();
    }

    return total_score / simulation_runs;

};

#endif
