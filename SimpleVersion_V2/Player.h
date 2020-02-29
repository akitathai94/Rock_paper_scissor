//
// Created by Prajjwal Singhal on 2020-02-28.
//

#ifndef RPS_PLAYER_H
#define RPS_PLAYER_H

#include <iostream>
#include "OPTIONS.h"

class Player {
    public:
    void set_choice(OPTIONS ch) { choice = ch;};
    OPTIONS get_choice()        { return choice;};
    private:
    OPTIONS choice;
};


#endif //TESTPROGRAM_PLAYER_H
