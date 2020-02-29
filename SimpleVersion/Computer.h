#ifndef COMPUTER_RPS
#define COMPUTER_RPS
#include <iostream>
#include "Player.h"

using namespace std;

class Computer: public Player {
	public:
		Computer(); // default constructor

		// choice making function
		OPTIONS make_choice();
};

#endif