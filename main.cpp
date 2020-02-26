#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;
class Player {
    private:
        enum choice{
            ROCK, PAPER, SCISSOR, NO_CHOICE
        };
    public:
        void set__choice();
};

class Game {
    private:
        const int ROUNDS;
        int round_count;
        Player human_player,machine_player;
        int human_result,machine_result;
    public:
        Game();
        void set__round_count(int round_th);
        int get__round_count();
        void set_result(Player winner);
        int get__human_result();
        int get__machine_result();
        void is_roundWinner();  // Most important logic of the program
        void is_gameWinner();
        void start_game(); // clear choice after each round
};

int main(){
    Game();
}
void Game::set__round_count(int round_t){
    round_count = round_t;
}
Game::Game(void) {
    const int ROUNDS = 20; // should not be changed 
    human_player(3), machine_player(3);
    set__round_count(0);
}
int Game::get__machine_result(){
    return machine_result;
}
int Game::get__human_result(){
    return human_result;
}
void Game::set_result(Player winner){
    if(winner == human_player){
        human_result++;
    } else if (winner == machine_player){
        machine_result++;
    }
}

void Game::is_gameWinner(){
    if(human_result > machine_result){
        cout<<"Congratulation, you have won the game over machine\n";
    } else if (human_result < machine_result){
        cout<<"The machine have won the game, good luck next time\n";
    } else cout<<"Tie game !!!\n";
}

int Game::get__round_count(){
    return round_count;
}