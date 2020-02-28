#ifndef GAME_RPS
#define GAME_RPS
#include "Player.h"
#include "OPTION.h"
class Game {
    private:
        bool is_Over;
        int round_count;
        Player human_player,machine_player;
    public:
        bool game_is_Over();
        void set__game_Over(bool);
        Game();
        bool is__draw(); // check if it is draw or not
        void set__next_round();
        int get__round_count();
        void set__round_players_choice(int human_choice, int machine_choice);
        void set__round_result(Player winner);
        int get__human_result();
        int get__machine_result();
        void is_roundWinner();  // Most important logic of the program
        void is_gameWinner();
        void start_round(); // clear choice after each round
};

#endif
