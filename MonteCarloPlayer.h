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
	public:
        MonteCarloPlayer() {
            name = "MonteCarloPlayer (Hueristic)";
        }
        char getMove(const Board&);
        virtual double simulation(const Board&);
};

char MonteCarloPlayer::getMove(const Board& board) {

    char bestMove;
    double bestScore = -1.0;
    vector<char> directions = {'u', 'd', 'l', 'r'};

    for (int i = 0; i < directions.size(); i++) {
        Board tempBoard(board);
        tempBoard.makeMove(directions[i]);

        double score = simulation(tempBoard);
        
        if (score > bestScore) {
            bestScore = score;
            bestMove = directions[i];
        }
    }
    return bestMove;
    
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
