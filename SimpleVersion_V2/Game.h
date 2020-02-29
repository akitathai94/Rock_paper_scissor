//
// Created by Prajjwal Singhal on 2020-02-28.
//

#ifndef RPS_GAME_H
#define RPS_GAME_H

#include "Round.h"
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

class Game {

    public:
    Game(int );
    GAME_RESULT getCurrentRoundWinner(OPTIONS );
    int get_current_round_no();
    GAME_RESULT getFinalGameWinner();
    OPTIONS getCurrentRoundComputerChoice() {return rounds[current_round-1].get_computer_choice();}

    private:
    int totalRounds;
    OPTIONS generateComputerChoice();
    int no_of_player_wins, no_of_computer_wins;
    int current_round;
    vector<Round> rounds;
};


#endif //TESTPROGRAM_GAME_H
