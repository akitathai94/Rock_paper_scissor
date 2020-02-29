//
// Created by Prajjwal Singhal on 2020-02-28.
//

#ifndef RPS_GAMERESULT_H
#define RPS_GAMERESULT_H

#include <iostream>
using namespace std;

enum GAME_RESULT{
    // This class is used so that we can restrict the game results to 3 options and not use int for representing game result
    PLAYER_WON, COMPUTER_WON, DRAW
};

inline ostream& operator<<(ostream& ostr, const GAME_RESULT opt)
{
    switch(opt)
    {
        case GAME_RESULT::PLAYER_WON : ostr <<"Player Won!!"; break;
        case GAME_RESULT::COMPUTER_WON: ostr <<"Computer Won!!"; break;
        case GAME_RESULT::DRAW: ostr <<"Draw!!"; break;
    }
    return ostr;
}

#endif //TESTPROGRAM_GAMERESULT_H
