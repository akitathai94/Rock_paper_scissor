#include "Game.h"

bool Game::is__draw(){
    return machine_player.get__choice() == human_player.get__choice();
}

void Game::set__round_count(int round_t){
    round_count = round_t;
}

Game::Game(void) {
    const int ROUNDS = 20; // should not be changed 
    human_player(3), machine_player(3);
    set__round_count(0);    // Why call a setter, when variable can be accessed directly
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