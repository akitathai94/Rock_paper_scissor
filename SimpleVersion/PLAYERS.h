#ifndef PLAYERS_RPS
#define PLAYERS_RPS
#include <iostream>
#include "Options.h"
using namespace std;

class Players {

	public:
		Players(); // default constructor

		// accessors
		int get_current_score() { return current_score; }
		int get_number_of_rounds_played()  { return number_of_rounds_played; }
		OPTIONS get_current_choice()  { return current_choice; }

		// mutators
		void set_current_score(int);
		void set_number_of_rounds_played(int);
		void set_current_choice(OPTIONS);

	private:
		int current_score;
		int number_of_rounds_played;
		OPTIONS current_choice;
};
#endif
