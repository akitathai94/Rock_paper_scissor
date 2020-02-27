#include "Game.h"

Game::Game(void) {
    set__rounds(20); // fixed if using default constructor
    set__is_over(false);
    set__round_count(0); // game not started yet.
    human_player = new Player();
    machine_player = new Player();
    human_score = -1; // negative score before game starts
    machine_score = -1; // negative score before game starts
}

Game::Game(int game_rounds) {
    Game();
    set__rounds(game_rounds);
}

void set__rounds(int game_rounds){
    rounds = game_rounds;
}

void Game::set__is_over(bool is_game_over){
    is_over = is_game_over;
}

bool Game::is__round_draw(){
    return machine_player.get__choice() == human_player.get__choice();
}

void Game::set__current_round_count(int current_round_count){
    this->current_round_count = current_round_count;
}

int Game::get__machine_score(){
    return machine_score;
}

int Game::get__human_score(){
    return human_score;
}

void Game::set_result(Player winner){
    if(winner == human_player){
        human_score++;
    } else if (winner == machine_player){
        machine_score++;
    }
}

void Game::is_game_winner(){
    if(human_score > machine_score){
        cout<<"Congratulations, you have won the game vs a machine!\n";
    }
    else if (human_score < machine_score){
        cout<<"The machine won the game, good luck next time!\n";
    }
    else cout<<"Tie game!\n";
}

int Game::get__round_count(){
    return round_count;
}

//Player is_round_winner();  // Most important logic of the program