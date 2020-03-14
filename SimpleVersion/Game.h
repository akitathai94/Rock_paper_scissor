#ifndef GAME_RPS
#define GAME_RPS

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "OPTIONS.h"
#include "Player.h"
#include "GameResult.h"
#include "Round.h"
using namespace std;

//class Game {
//
//    public:
//
//        // constructors
//        Game(); // default constructor
//        Game(Human h_player, Computer c_player, int rounds = MAX_ROUNDS_IN_GAME); // parameterized constructor. parameter specifies number of rounds to play in the game.
//
//        // starts and carries out a game.
//        void play_a_game();
//
//    private:
//        // accessors
//        // Human get_human_player() {;}
//        // Computer get_computer_player() {;}
//        int get_number_of_rounds_to_play() { return number_of_rounds_to_play; }
//        int get_current_round_number() { return current_round_number;}
//
//        // mutators
//        void set_number_of_rounds_to_play(int);
//        void set_current_round_number(int);
//
//        // functions
//        void play_a_round();
//        void play_a_game();
//
//
//        // helper functions
//        void decide_round_winner();
//        void update_number_of_rounds();
//        void decide_game_winner();
//
//        // variables
//        Human human_player;
//        Computer computer_player;
//        int number_of_rounds_to_play;
//        int current_round_number;
//};

class Game{
public:
    Game(int, string, string);          // constructor to initialize the number of games, human algo, computer algo
    GAME_RESULT play_a_round();             // to play a single round and return the winner

    GAME_RESULT get_game_winner();      //  return the winner of the final game
    GAME_RESULT get_round_winner(int ); // return the winner of a particular round
    GAME_RESULT get_last_round_winner();// return the winner of the last round

    OPTIONS get_human_choice(int );     // return human choice for a particular round
    OPTIONS get_computer_choice(int );  // return Computer choice for a particular round
    OPTIONS get_last_human_choice();    // return the last choice made by human
    OPTIONS get_last_computer_choice();  // return the last choice made by computer

    int get_current_human_score();      //
    int get_current_computer_score();   //
    GAME_RESULT play_full_game();
private:
    Player *human, *computer;
    int humanWins, computerWins;
    vector<Round> rounds;
    int totalRounds;

    void print_results(ostream& ,OPTIONS , OPTIONS , GAME_RESULT , int);
    string computer_algo;
};
#endif