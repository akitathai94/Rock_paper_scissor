//
// Created by Prajjwal Singhal on 2020-02-28.
//

#include "Round.h"

Round :: Round(OPTIONS pCHoice, OPTIONS cChoice) {
    playerChoice = pCHoice;
    computerChoice = cChoice;
}

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
    // -1 if computer is winner
    // 0 if draw
    // 1 if player is winner
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
