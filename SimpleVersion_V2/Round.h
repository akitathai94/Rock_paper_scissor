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
    /*
     * A round has two choices and it decided who won that round, it also stores the two choices
     */
    Round();
    Round(OPTIONS , OPTIONS );                  // Set the choices for both player and computer
    void set_player_choice(OPTIONS );           // update the player choice if needed
    void set_computer_choice(OPTIONS choice);   // update the computer choice if needed
    OPTIONS get_player_choice();                // return the choice made by the player
    OPTIONS get_computer_choice();              // return the choice made by the computer
    GAME_RESULT getWinner();                    // get the winner of the current round
    OPTIONS getHumanChoice();                   // Code to get human choice
    OPTIONS getComputerChoice();                // generate the computer's choice
private:
    OPTIONS playerChoice, computerChoice;       // store the two choices
};


#endif //TESTPROGRAM_ROUND_H
