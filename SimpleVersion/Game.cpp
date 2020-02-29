#include "Game.h"

#define MAX_ROUNDS_IN_GAME = 20;
// constructors

// default constructor 
Game::Game() {
    Human human_player = new Human();
    Computer computer_player = new Computer();
    int number_of_rounds_to_play = MAX_ROUNDS_IN_GAME; // default value
    int current_round_number = -1; // default value
}

// parameterized constructor
// parameter specifies number of rounds to play in the game.
Game::Game(int rounds) {
    Human human_player = new Human();
    Computer computer_player = new Computer();
    int number_of_rounds_to_play = rounds; // custom value
    int current_round_number = -1; // default value   
}

// mutators
void Game::set_number_of_rounds_to_play(int rounds) {
    number_of_rounds_to_play = rounds;
}
void Game::set_current_round_number(int round_num) {
    current_round_number = round_num
}

// functions
void Game::play_a_round(); // TODO
void Game::play_a_game();  // TODO


// helper functions
void Game::decide_round_winner();  // TODO
void Game::update_number_of_rounds();  // TODO
void Game::decide_game_winner();  // TODO

////////////////////////////////////////
////////////////////////////////////////
////////////////////////////////////////
////////////////////////////////////////
/*
Game :: Game(int total_rounds){
    no_of_rounds = total_rounds;
    user_wins_count = 0;
    computer_wins_count = 0;
    current_round_no = 0;
    srand(time(0));
}

int Game :: getRoundWinner(OPTIONS userChoice)
{
    // -1 if computer won
    //  0 if draw
    //  1 if user won
    current_round_computer_choice = getComputerChoice();
    int x = compareChoices(current_round_computer_choice, userChoice);
    switch (x)
    {
        case -1:    computer_wins_count++;
            break;
        case 1:     user_wins_count++;
            break;
        default:
            break;
    }
    current_round_no++;
    return x;
}

int Game :: getGameWinner()
{
    // -1 if computer won
    //  0 if draw
    //  1 if user won
    if(user_wins_count > computer_wins_count)
        return 1;
    else if(computer_wins_count > user_wins_count)
        return -1;
    return 0;
}

OPTIONS Game :: getComputerChoice()
{
    // return the choice made by computer
    return static_cast<OPTIONS>(rand()%3);
}
int Game :: compareChoices(const OPTIONS choice1, const OPTIONS choice2)
{
    // -1 if choice1 is winner
    // 0 if draw
    // 1 if choice2 is winner
    switch(choice1)
    {
        case OPTIONS::ROCK :    if(choice2 == OPTIONS::SCISSOR) return -1;
                                else if(choice2==OPTIONS::PAPER) return 1;
                                else return 0;
                                break;
        case OPTIONS::SCISSOR : if(choice2 == OPTIONS::PAPER) return -1;
                                else if(choice2==OPTIONS::ROCK) return 1;
                                else return 0;
                                break;                      
        case OPTIONS::PAPER : if(choice2 == OPTIONS::ROCK) return -1;
                                else if(choice2==OPTIONS::SCISSOR) return 1;
                                else return 0;
                                break; 
            
    }
    return 0;
}
*/