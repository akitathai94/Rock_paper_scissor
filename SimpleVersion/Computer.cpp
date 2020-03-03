#include "Computer.h"

Computer::Computer() : Player() {
	// nothing to do here.
} 

// choice making function
OPTIONS Computer::make_choice() {
    OPTIONS generated_choice = static_cast<OPTIONS>(rand()%3);
    Player::set_current_choice(generated_choice);
    return generated_choice;
}