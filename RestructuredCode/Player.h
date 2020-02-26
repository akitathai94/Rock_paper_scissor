#ifndef PLAYER_RPS
#define PLAYER_RPS
#include "OPTION.h"
class Player {
    private:
        OPTION choice;
    public:
        void set__choice(OPTION user_choice);
        OPTION get__choice();
};

#endif