#include "Player.h"

void Player::set_current_score(int score) {
	this->current_score = score;
}
void Player::set_number_of_rounds_played(int num_rounds_played) {
	this->number_of_rounds_played = num_rounds_played;
}
void Player::set_current_choice(OPTIONS choice) {
	this->current_choice = choice;
}