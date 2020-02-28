#ifndef GAME_RPS
#define GAME_RPS

#include <iostream>
#include <ctime>
#include <cstdlib>
#include "OPTIONS.h"
using namespace std;
class Game{
    int user_wins_count;                // Number of times user won
    int computer_wins_count;            // Number of times computer won
    int no_of_rounds;                   // Total Number of rounds
    int current_round_no;               // Round that is currently going on
    OPTIONS getComputerChoice();            // Logic to generate computer choice
    int compareChoices(const OPTIONS , const OPTIONS);            // return the winner of two choices
    OPTIONS current_round_computer_choice;
    public:
    
    Game(int );                         // Constructor
    int getRoundWinner(OPTIONS );       // returns winner based on user input
    int getGameWinner();                // returns the winner of final game
    OPTIONS getCurrentRoundComputerChoice() {return current_round_computer_choice;};
    int getCurrentRoundNo() {return current_round_no;};
};

#endif