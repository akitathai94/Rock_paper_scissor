#include "Game.h"
#include "iostream"
#include "cstdlib"
#include "time.h"
using namespace std;
bool Game::is__draw(){
    return machine_player.get__choice() == human_player.get__choice();
}

void Game::set__game_Over(bool logic){
    is_Over = logic;
}
void Game::set__next_round(){
    round_count = round_count + 1;
}
bool Game::game_is_Over(){
    return is_Over;
}
int Game::get__human_result(){
    return human_player.get__result();
}
int Game::get__machine_result(){
    return machine_player.get__result();
}
Game::Game() {
    human_player.set__choice(NO_CHOICE);
    machine_player.set__choice(NO_CHOICE);
    is_Over = false;
    round_count = 0;
}
void Game::set__round_players_choice(int human_choice, int machine_choice ){
    human_player.set__choice(human_choice);
    machine_player.set__choice(machine_choice);
}

void Game::is_roundWinner() {
    Player winner;
    if(((human_player.get__choice() == ROCK) && (machine_player.get__choice() == SCISSOR)) ||
    ((human_player.get__choice() == PAPER) && (machine_player.get__choice() == ROCK)) ||
    ((human_player.get__choice() == SCISSOR) && (machine_player.get__choice() == PAPER)))
    {
        human_player.set__win_round();
    } else machine_player.set__win_round();
}
void Game::is_gameWinner(){
    if(human_player.get__result() > machine_player.get__result()){
        cout<<"Congratulation, you have won the game over machine\n";
    } else if (human_player.get__result() < machine_player.get__result()){
        cout<<"The machine have won the game, good luck next time\n";
    } else cout<<"Tie game !!!\n";
}

int Game::get__round_count(){
    return round_count;
}

void Game::start_round(){
    human_player.set__choice(3);
    machine_player.set__choice(3);
}
