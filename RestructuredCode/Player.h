#ifndef PLAYER_RPS
#define PLAYER_RPS
#include "OPTION.h"
class Player {
    public:
    	Player();
        void set__choice(OPTION user_choice);
        OPTION get__choice();

    private:
        OPTION choice;
};

#endif