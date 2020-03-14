//
// Created by Prajjwal Singhal on 2020-02-28.
//

#ifndef RPS_GAME_H
#define RPS_GAME_H

#include "Round.h"
#include <vector>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <string>
#include <map>
using namespace std;

class Game {

    public:
    Game();                                         // Default Constructor make sure the size is 5 so you can play both mode 
    Game(int );                                     // Constructor to initialize total no. of rounds
    ~Game();                                        // Deconstructor to Game()
    
    GAME_RESULT getCurrentRoundWinner(OPTIONS );    // To get round winner based on an input choice
    int get_current_round_no();                     // get the round that is currently going on
    GAME_RESULT getFinalGameWinner();               // The winner of the total game
    OPTIONS getCurrentRoundComputerChoice();        // the choice that computer made in the current round
    OPTIONS getCurrentRoundPlayerChoice();          // the choice that Player made in the current round
    OPTIONS getHumanChoice();                       // Code to get human choice
     OPTIONS generateComputerChoiceRandom();               // generate the computer's choice random
    OPTIONS generateComputerChoiceML(); //generate the computer 's choice machine learning
    OPTIONS generateToWinChoice(char choice);            // Generate to choice that win the choicei n the parameters
    void loadFileToDict();
    void loadDicttoFile();
    private:
    /*
     * A game consists of multiple rounds, and keeps track of the number of times each player won
     * A game also has logic for computer generated choice
     */
    int totalRounds;                                // Total number of rounds in a game
   
    
    int no_of_player_wins, no_of_computer_wins;     // keep track of who won how many rounds
    vector<Round> rounds;                           // Stores history of all previous rounds
                                                    // to make code more flexible in case they are needed
    map <string,int> dict;
};


#endif //TESTPROGRAM_GAME_H
