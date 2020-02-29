#ifndef HUMAN_RPS
#define HUMAN_RPS
#include <iostream>
#include "Player.h"

using namespace std;

class Human: public Player {
	public:
		Human(); // default constructor

		// choice making function
		OPTIONS read_choice();
};

#endif