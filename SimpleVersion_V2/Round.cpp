//
// Created by Prajjwal Singhal on 2020-02-28.
//

#include "Round.h"

Round :: Round(OPTIONS pCHoice, OPTIONS cChoice) {
    playerChoice = pCHoice;
    computerChoice = cChoice;
}
Round :: Round(){}

void Round ::set_player_choice(OPTIONS choice) {
    playerChoice =choice;
}

void Round ::set_computer_choice(OPTIONS choice){
    computerChoice =choice;
}

OPTIONS Round ::get_computer_choice() {
    return computerChoice;
}

OPTIONS Round ::get_player_choice(){
    return playerChoice;
}
GAME_RESULT Round ::getWinner() {
    switch(computerChoice)
    {
        case OPTIONS::ROCK :    if(playerChoice == OPTIONS::SCISSOR) return GAME_RESULT::COMPUTER_WON;
                                else if(playerChoice==OPTIONS::PAPER) return GAME_RESULT::PLAYER_WON;
                                else return GAME_RESULT::DRAW;

        case OPTIONS::SCISSOR : if(playerChoice == OPTIONS::PAPER) return GAME_RESULT::COMPUTER_WON;
                                else if(playerChoice==OPTIONS::ROCK) return GAME_RESULT::PLAYER_WON;
                                else return GAME_RESULT::DRAW;

        case OPTIONS::PAPER :   if(playerChoice == OPTIONS::ROCK) return GAME_RESULT::COMPUTER_WON;
                                else if(playerChoice==OPTIONS::SCISSOR) return GAME_RESULT::PLAYER_WON;
                                else return GAME_RESULT::DRAW;

    }
    return GAME_RESULT::DRAW;
}
OPTIONS Round ::getHumanChoice() {
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
OPTIONS Round ::getComputerChoice() {
    return static_cast<OPTIONS>(rand()%3);
}