#include "Player.h"

OPTION Player::get__choice(){
    return choice;
}
void Player::set__choice(int user_choice){
    // Type cast int to enum OPTION
    choice = static_cast<OPTION>(user_choice);
}

int Player::get__result(){
    return result;
}

void Player::set__result(int _result){
    result = _result;
}

Player::Player() {
    set__choice(3); // set to NO_CHOICE option
    set__result(0);
}

void Player::set__win_round(){ // increase score by 1
    result = result +1;
}
