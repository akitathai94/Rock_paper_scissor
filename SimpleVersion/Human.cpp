#include "Human.h"

Human::Human() : Player() {
	// nothing to do here.
} 

// choice making function
OPTIONS Human::read_choice() {
    int entered_choice = -1; // default choice
    cout << "Choices:" << endl;
    cout << "0 = Rock" << endl;
    cout << "1 = Paper" << endl;
    cout << "2 = Scissors" << endl;

    cout << "Enter your choice: ";
    cin >> entered_choice;
    OPTIONS var;
    
    switch(entered_choice)
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
}