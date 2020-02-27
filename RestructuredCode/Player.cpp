#include "Player.h"

Player::Player(){
	set__choice(OPTION::NO_CHOICE);
}


OPTION Player::get__choice(){
    return choice;
}
void Player::set__choice(OPTION user_choice){
    choice = user_choice;
}