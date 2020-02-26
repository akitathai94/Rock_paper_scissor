#ifndef GAME_RPS
#define GAME_RPS
#include "Player.h"
#include "OPTION.h"
class Game {
    private:
        bool is_Over;
        const int ROUNDS;
        int round_count;
        Player human_player,machine_player;
        int human_result,machine_result;
    public:
        Game();
        bool is__draw(); // check if it is draw or not 
        void set__round_count(int round_th);
        int get__round_count();
        void set_result(Player winner);
        int get__human_result();
        int get__machine_result();
        Player is_roundWinner();  // Most important logic of the program
        void is_gameWinner();
        void start_round(); // clear choice after each round
};

#endif