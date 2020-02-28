#include <iostream>
#include "Game.h"
using namespace std;

int main()
{
    Game g(1);
    int choice = 0;
    cout << "Choices" << endl;
    cout << "0 = Rock" << endl;
    cout << "1 = Paper" << endl;
    cout << "2 = Scissor" << endl;
    int winner; 
    for(int i = 0; i < 5; i++)
    {
        cout << "Enter your choice: ";
        cin >> choice;
        OPTIONS var;
        if(choice == 0)
            var = OPTIONS::ROCK;
        else if(choice == 1)
            var = OPTIONS::PAPER;
        else if(choice == 1)
            var = OPTIONS::SCISSOR;
        winner = g.getRoundWinner(var);
        cout << "You chose: " << var << endl << "The computer chose: " << g.getCurrentRoundComputerChoice() << endl;
        if(winner == -1)
            cout << "Computer Won!!" << endl;
        else if(winner == 1)
            cout << "Player Won!!" << endl;
        else if(winner == 0)
            cout << "Draw!!" << endl;

        cout << "---------- END of Round " << g.getCurrentRoundNo() << "-------------" << endl;
            
    }
    winner = g.getGameWinner();
    if(winner == -1)
        cout << "Computer Won the total game!!" << endl;
    else if(winner == 1)
        cout << "Player Won the total game!!" << endl;
    else if(winner == 0)
        cout << "The game was a Draw!!" << endl;
    return 0;
}