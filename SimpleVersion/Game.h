#ifndef GAME_RPS
#define GAME_RPS

#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Options.h"

using namespace std;

class Game{
/*    int user_wins_count;                // Number of times user won
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
*/
    public:

        // constructors
        Game(); // default constructor
        Game(int); // parameterized constructor. parameter specifies number of rounds to play in the game.

        // accessors
        // Human get_human_player() {;}
        // Computer get_computer_player() {;}
        int get_number_of_rounds_to_play() { return number_of_rounds_to_play; }
        int get_current_round_number() { return current_round_number;}       

        // mutators
        void set_number_of_rounds_to_play(int);
        void set_current_round_number(int); 

        // functions
        void play_a_round();
        void play_a_game();


        // helper functions
        void decide_round_winner();
        void update_number_of_rounds();
        void decide_game_winner();

    private:
        Human human_player;
        Computer computer_player;
        int number_of_rounds_to_play;
        int current_round_number;
};

#endif