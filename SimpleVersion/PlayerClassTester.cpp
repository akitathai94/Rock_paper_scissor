//
// Created by Prajjwal Singhal on 2020-03-12.
//

#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "Player.h"
#include "OPTIONS.h"
#include "ChooserType.h"

int main(int argc, char **argv) {
	if ((argc < 2) || (argv[1] != "-r" || argv[1] != "-m")) {
		printf("USAGE: %s -r OR  %s -m\n", argv[0]);
		exit(2); // user did not specify an appropriate alg for the computer to use.
	}

	CHOOSER_TYPE algorithm_type_specified;
	if (argv[1] == "-r") {
		algorithm_type_specified = CHOOSER_TYPE::RANDOM;
	}

	else if (argv[1] == "-m") {
		algorithm_type_specified = CHOOSER_TYPE::ML;
	}

    srand ( time(NULL) );
    Player p1(CHOOSER_TYPE::HUMAN);
    OPTIONS var;
    int rock = 0, paper = 0, scissor = 0;
    for(int i = 0; i < 10; i++){
        var = p1.get_choice();
        switch (var){
            case OPTIONS::PAPER : paper++; break;
            case OPTIONS::ROCK : rock++; break;
            case OPTIONS::SCISSORS : scissor++; break;
        }
    }
    // Check to see if the the number of times each is chosen is random or not
    cout << "ROCK = " << rock << endl;
    cout << "PAPER = " << paper << endl;
    cout << "SCISSOR =" << scissor << endl;


    return 0;
}