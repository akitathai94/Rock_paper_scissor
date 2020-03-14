#include "Player.h"

//Player::Player() {
//	current_score = 0;	// default score
//	number_of_rounds_played = -1;	// default number of rounds played
//	current_choice = OPTIONS::DEFAULT_CHOICE;
//}
//
//void Player::set_current_score(int score) {
//	this->current_score = score;
//}
//void Player::set_number_of_rounds_played(int num_rounds_played) {
//	this->number_of_rounds_played = num_rounds_played;
//}
//void Player::set_current_choice(OPTIONS choice) {
//	this->current_choice = choice;
//}

Player :: Player(CHOOSER_TYPE which){

    ChooserFactory c;
    ChoiceMaker = c.make_chooser(which);
}

//OPTIONS Player ::get_choice() {
//    return ChoiceMaker->make_choice();
//}


OPTIONS Player ::get_choice(vector<Round> rounds) {
    return ChoiceMaker->make_choice(rounds);
}