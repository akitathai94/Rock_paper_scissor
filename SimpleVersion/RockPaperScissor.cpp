#include <iostream>
#include "Game.h"
#include "ChooserType.h"
#include <string>
using namespace std;

const int MAX_ROUNDS = 20;
int main(int argc, char **argv) {

    if (argc < 2){
        printf("USAGE: %s -r OR -m\n", argv[0]);
    }
    string input(argv[1]);
//    if ((argc < 2) || (argv[1] != "-r" || argv[1] != "-m")) {
//        printf("USAGE: %s -r OR -m\n", argv[0]);
//        exit(2); // user did not specify an appropriate alg for the computer to use.
//    }

    CHOOSER_TYPE algorithm_type_specified;
    if (input == "-r") {
        algorithm_type_specified = CHOOSER_TYPE::RANDOM;
    }

    else if (input == "-m") {
        algorithm_type_specified = CHOOSER_TYPE::ML;
    }
    srand ( time(NULL) );

    cout << "Choices" << endl;
    cout << "0 = Rock" << endl;
    cout << "1 = Paper" << endl;
    cout << "2 = Scissor" << endl;

    Game g(MAX_ROUNDS, CHOOSER_TYPE::HUMAN, algorithm_type_specified, 5);

    GAME_RESULT winner = g.play_full_game();

    cout << endl << "Final Game Result:" << winner << endl << endl;

    cout << "Human Won: " << g.get_current_human_score() << endl;
    cout << "Computer Won: " << g.get_current_computer_score() << endl;

    return 0;
}
// ./myProgram r