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

    for(int i = 0; i < 5; i++)
    {
        cout << "Enter your choice: ";
        cin >> choice;
        cout << g.getRoundWinner(OPTIONS::ROCK) << endl;
    }

    cout << g.getGameWinner() << endl;
    return 0;
}