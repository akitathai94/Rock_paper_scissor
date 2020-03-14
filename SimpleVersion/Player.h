#ifndef PLAYER_RPS
#define PLAYER_RPS
#include <iostream>
#include <string>
#include <vector>
#include "OPTIONS.h"
#include "Chooser.h"
#include "Round.h"
#include "ChooserFactory.h"
#include <ctime>
#include <cstdlib>

using namespace std;

//class Player {
//
//	public:
//		Player(); // default constructor
//
//		// accessors
//		int get_current_score() { return current_score; }
//		int get_number_of_rounds_played()  { return number_of_rounds_played; }
//		OPTIONS get_current_choice()  { return current_choice; }
//
//		// mutators
//		void set_current_score(int);
//		void set_number_of_rounds_played(int);
//		void set_current_choice(OPTIONS);
//
//	private:
//		int current_score;
//		int number_of_rounds_played;
//		OPTIONS current_choice;
//};

class Player{
public:
    Player(string which); // constructor
    //OPTIONS get_choice();   // delegates task to chooser
    OPTIONS get_choice(vector<Round>); // delegate task to MLChooser
private:
    Chooser *ChoiceMaker;

};
#endif
