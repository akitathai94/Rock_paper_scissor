#ifndef GAME_RPS
#define GAME_RPS
#include "Player.h"
#include "OPTION.h"
class Game {
    public:
        Game(); // default constructor. Sets ROUNDS = 20. 
        Game(int game_rounds); // parameterized constructor

        Player is_round_winner();  // Most important logic of the program
        bool is__round_draw(); // checks if there has been a draw for a round   
        void is_game_winner();

        void set__is_over(bool is_game_over);

        void set__rounds(int game_rounds);

        // getters and setters for round_count
        void set__current_round_count(int current_round_count);
        int get__round_count();

        // update the results based on winner
        void set_result(Player winner);
        int get__human_score();
        int get__machine_score();

        void start_round(); // clear choice after each round

    private:
        bool is_over;
        const int rounds;
        int current_round_count;
        Player human_player, machine_player;
        int human_score, machine_score;
};

#endif