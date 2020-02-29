//
// Created by Prajjwal Singhal on 2020-02-28.
//

#ifndef TESTPROGRAM_ROUND_H
#define TESTPROGRAM_ROUND_H

#include <iostream>
#include "OPTIONS.h"
#include "GameResult.h"
using namespace std;

class Round {
public:
    Round(OPTIONS , OPTIONS );
    void set_player_choice(OPTIONS );
    void set_computer_choice(OPTIONS choice);
    OPTIONS get_player_choice();
    OPTIONS get_computer_choice();
    GAME_RESULT getWinner();
private:
    OPTIONS playerChoice, computerChoice;
};


#endif //TESTPROGRAM_ROUND_H
