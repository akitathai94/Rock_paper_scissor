//
// Created by Prajjwal Singhal on 2020-02-28.
//

#include "Game.h"

Game :: Game(int max_rounds){
    no_of_player_wins = 0;
    no_of_computer_wins = 0;
    totalRounds = max_rounds;
    srand(time(0));
}

int Game ::get_current_round_no() {
    return rounds.size();
}

GAME_RESULT Game ::getCurrentRoundWinner(OPTIONS player_choice) {

    OPTIONS computer_choice = generateComputerChoice();

    Round r(player_choice, computer_choice);

    rounds.push_back(r);
    GAME_RESULT g = r.getWinner();

    switch(g)
    {
        case GAME_RESULT::PLAYER_WON : no_of_player_wins++; break;
        case GAME_RESULT::COMPUTER_WON: no_of_computer_wins++; break;
    }
    return g;
}

OPTIONS Game ::generateComputerChoice() {
    return static_cast<OPTIONS>(rand()%3);
}

GAME_RESULT Game :: getFinalGameWinner(){
    if(no_of_computer_wins > no_of_player_wins)
        return GAME_RESULT :: COMPUTER_WON;

    else if(no_of_player_wins > no_of_computer_wins)
        return GAME_RESULT :: PLAYER_WON;

    return GAME_RESULT :: DRAW;
}

OPTIONS Game :: getCurrentRoundComputerChoice(){
    return rounds[rounds.size()-1].get_computer_choice();
}
OPTIONS Game :: getCurrentRoundPlayerChoice(){
    return rounds[rounds.size()-1].get_player_choice();
}
OPTIONS Game :: getHumanChoice(){
    int choice;
    cout << "Enter your choice: ";
    cin >> choice;
    OPTIONS var;
    if(choice == 0)
        var = OPTIONS::ROCK;
    else if(choice == 1)
        var = OPTIONS::PAPER;
    else if(choice == 2)
        var = OPTIONS::SCISSOR;

    return var;
}