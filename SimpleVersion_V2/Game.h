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
    Game(int );                                     // Constructor to initialize total no. of rounds
    GAME_RESULT getCurrentRoundWinner(OPTIONS );    // To get round winner based on an input choice
    int get_current_round_no();                     // get the round that is currently going on
    GAME_RESULT getFinalGameWinner();               // The winner of the total game
    OPTIONS getCurrentRoundComputerChoice();        // the choice that computer made in the current round
    OPTIONS getCurrentRoundPlayerChoice();          // the choice that Player made in the current round
    OPTIONS getHumanChoice();                       // Code to get human choice
    private:
    /*
     * A game consists of multiple rounds, and keeps track of the number of times each player won
     * A game also has logic for computer generated choice
     */
    int totalRounds;                                // Total number of rounds in a game
    OPTIONS generateComputerChoice();               // generate the computer's choice

    int no_of_player_wins, no_of_computer_wins;     // keep track of who won how many rounds
    vector<Round> rounds;                           // Stores history of all previous rounds
                                                    // to make code more flexible in case they are needed
};


#endif //TESTPROGRAM_GAME_H
