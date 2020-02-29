//
// Created by Prajjwal Singhal on 2020-02-28.
//

#include <iostream>
#include "Game.h"
using namespace std;

int main()
{
    Game g(5);
    int choice = 0;
    GAME_RESULT winner;
    cout << "Choices" << endl;
    cout << "0 = Rock" << endl;
    cout << "1 = Paper" << endl;
    cout << "2 = Scissor" << endl;
    for(int i = 0; i < 5; i++)
    {

        OPTIONS var = g.getHumanChoice();
        winner = g.getCurrentRoundWinner(var);
        cout << "You chose: " << g.getCurrentRoundPlayerChoice() << endl << "The computer chose: " << g.getCurrentRoundComputerChoice() << endl;

        cout << winner << endl;

        cout << "---------- END of Round " << g.get_current_round_no() << "-------------" << endl;

    }

    cout << "The final result of the game is" << endl;
    cout << g.getFinalGameWinner();

    return 0;
}