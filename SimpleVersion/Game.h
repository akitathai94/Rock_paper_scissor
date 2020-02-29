#ifndef GAME_RPS
#define GAME_RPS

#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Options.h"

using namespace std;

class Game {

    public:

        // constructors
        Game(); // default constructor
        Game(Human h_player, Computer c_player, int rounds = MAX_ROUNDS_IN_GAME); // parameterized constructor. parameter specifies number of rounds to play in the game.

        // starts and carries out a game. 
        void play_a_game();

    private:
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

        // variables
        Human human_player;
        Computer computer_player;
        int number_of_rounds_to_play;
        int current_round_number;
};

#endif