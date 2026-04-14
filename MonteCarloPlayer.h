#ifndef MONTECARLOPLAYER_H_
#define MONTECARLOPLAYER_H_

using namespace std;

#include "Board.h"
#include "Player.h"
#include <iostream>
#include <cstdlib>
#include <queue>
#include <vector>

class MonteCarloPlayer: public Player {
    int simulationRuns;
    int maxDepth;
    bool printScores;
	public:
        MonteCarloPlayer(int runs = 100, int depth = 0, bool printSimScores = false) {
            simulationRuns = runs;
            maxDepth = depth;
            printScores = printSimScores;
            name = "Monte Carlo Player";
        }
        char getMove(const Board&);
        double simulation(const Board&);
};

char MonteCarloPlayer::getMove(const Board& board) {

    char bestMove = 'u';
    double bestScore = -1.0;
    vector<char> directions = {'u', 'd', 'l', 'r'};

    for (int i = 0; i < directions.size(); i++) {
        Board tempBoard(board);
        tempBoard.makeMove(directions[i]);

        double score = simulation(tempBoard);
        if (printScores) {
            cout << "Move " << directions[i] << ": simulation score = " << score << endl;
        }
        if (score > bestScore) {
            bestScore = score;
            bestMove = directions[i];
        }
    }
    return bestMove;

};

double MonteCarloPlayer::simulation(const Board& board) {
    double total_score = 0.0;
    vector<char> directions = {'u', 'd', 'l', 'r'};

    for (int i = 0; i < simulationRuns; i++) {
        Board tempBoard(board);
        int steps = 0;
        while (tempBoard.canMove() && !tempBoard.hasWon()) {
            if (maxDepth > 0 && steps >= maxDepth) break;
            int randNum = rand() % directions.size();
            tempBoard.makeMove(directions[randNum]);
            tempBoard.addNewTile();
            steps++;
        }
        total_score += tempBoard.getCurrentScore();
    }

    return total_score / simulationRuns;

};

#endif
