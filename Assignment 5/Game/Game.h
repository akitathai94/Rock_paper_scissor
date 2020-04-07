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
#include "ChooserType.h"
using namespace std;


class Game{
public:
    Game(int, CHOOSER_TYPE, CHOOSER_TYPE, int n = 5);          // constructor to initialize the number of games, human algo, computer algo
    GAME_RESULT play_a_round();             // to play a single round and return the winner
    GAME_RESULT play_a_round(OPTIONS human_choice);     // In case human choice is sent as a parameter
    GAME_RESULT get_game_winner();      //  return the winner of the final game
    GAME_RESULT get_round_winner(int ); // return the winner of a particular round
    GAME_RESULT get_last_round_winner();// return the winner of the last round

    OPTIONS get_human_choice(int );     // return human choice for a particular round
    OPTIONS get_computer_choice(int );  // return Computer choice for a particular round
    OPTIONS get_last_human_choice();    // return the last choice made by human
    OPTIONS get_last_computer_choice();  // return the last choice made by computer

    int get_current_human_score();      //
    int get_current_computer_score();   //

    int get_number_of_rounds_played();  //
    bool is_game_finished();            //
    GAME_RESULT play_full_game();
private:
    Player *human, *computer;
    int humanWins, computerWins;
    vector<Round> rounds;
    int totalRounds;

    void print_results(ostream& ,OPTIONS , OPTIONS , GAME_RESULT , int);
    string computer_algo;
    int N;
};
#endif
