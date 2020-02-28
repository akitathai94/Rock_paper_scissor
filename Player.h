#ifndef PLAYER_RPS
#define PLAYER_RPS
#include "OPTION.h"
class Player {
    private:
        OPTION choice;
        int result;
    public:
        Player();  // Default Constructor;
        void set__choice(int user_choice);
        OPTION get__choice();
        void set__result(int _result);
        int get__result();
        void set__win_round();
};

#endif
