#include <iostream>
#include "Game.h"
#include "ChooserType.h"
using namespace std;


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

    cout << "Choices" << endl;
    cout << "0 = Rock" << endl;
    cout << "1 = Paper" << endl;
    cout << "2 = Scissor" << endl;

    Game g(100, CHOOSER_TYPE::HUMAN, algorithm_type_specified);
    GAME_RESULT winner = g.play_full_game();

    cout << endl << "Final Game Result:" << winner << endl << endl;

    cout << "Human Won: " << g.get_current_human_score() << endl;
    cout << "Computer Won: " << g.get_current_computer_score() << endl;

    return 0;
}
// ./myProgram r