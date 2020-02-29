#include "Computer.h"

Computer::Computer() : Player() {
	// nothing to do here.
} 

// choice making function
OPTIONS Computer::make_choice() {
    // int generated_choice = -1;

    // use random number generator to populate the generated_choice. 
    OPTIONS generated_choice = static_cast<OPTIONS>(rand()%3);
    /*OPTIONS var;
    
    switch(generated_choice)
    {
    	case 0:
    		var = OPTIONS::ROCK;
    		break;

    	case 1:
    		var = OPTIONS::PAPER;
    		break;

    	case 2:
    		var = OPTIONS::SCISSORS;
    		break;

    	default:
    		var = OPTIONS::DEFAULT_CHOICE;
    		// break;
    }
    
    Player::set_current_choice(var);
    */

    Player::set_current_choice(generated_choice);
}