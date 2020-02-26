#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;
enum OPTION{
            ROCK, PAPER, SCISSOR, NO_CHOICE
        };
class Player {
    private:
        OPTION choice;
    public:
        void set__choice(OPTION user_choice);
        OPTION get__choice();
};

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

int main(){
    Game();
}
bool Game::is__draw(){
    bool is_draw = FALSE;
    if(machine_player.get__choice() == human_player.get__choice()){
        is_draw = TRUE;
    }
    return is_draw;
}
OPTION Player::get__choice(){
    return choice;
}
void Player::set__choice(OPTION user_choice){
    choice = user_choice;
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

Player Game::is_roundWinner() {
    Player winner;
    if((human_player.get__choice() == ROCK) && (machine_player.get__choice() == SCISSOR) || 
    (human_player.get__choice() == PAPER) && (machine_player.get__choice() == ROCK) ||
    (human_player.get__choice() == SCISSOR) && (machine_player.get__choice == PAPER))
    {
        winner = human_player;
    } else winner = machine_player;
    return winner;
}