#ifndef COMPUTER_RPS
#define COMPUTER_RPS
#include <iostream>
#include "Player.h"

using namespace std;

class Computer: public Player {
	public:
		Computer(); // default constructor

		//Computer(TYPE_ENUM);	// parameterized constructor. 
		// ^ can be used to specify the type of make_choice() to be used,
		// when multiple versions are available. 

		// choice making function
		OPTIONS make_choice();
};

#endif