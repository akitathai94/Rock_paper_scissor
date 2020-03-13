#include <iostream>
#include "Game.h"
using namespace std;

int main()
{
    srand ( time(NULL) );

    cout << "Choices" << endl;
    cout << "0 = Rock" << endl;
    cout << "1 = Paper" << endl;
    cout << "2 = Scissor" << endl;

    Game g(10, "human", "random");
    GAME_RESULT winner = g.play_full_game();

    cout << endl << "Final Game Result:" << winner << endl << endl;

    cout << "Human Won: " << g.get_current_human_score() << endl;
    cout << "Computer Won: " << g.get_current_computer_score() << endl;

    return 0;
}