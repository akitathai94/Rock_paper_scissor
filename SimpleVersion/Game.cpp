#include "Game.h"

#define MAX_ROUNDS_IN_GAME = 20;
// constructors

// default constructor 
Game::Game() {
    human_player = new Human();
    computer_player = new Computer();
    number_of_rounds_to_play = MAX_ROUNDS_IN_GAME; // default value
    current_round_number = -1; // default value
}

// parameterized constructor
// parameter specifies number of rounds to play in the game.
Game::Game(Human h_player, Computer c_player, int rounds = MAX_ROUNDS_IN_GAME) {
    human_player = h_player;
    computer_player = c_player;
    number_of_rounds_to_play = rounds; // use custom value if provided
    current_round_number = -1; // default value
}

// mutators
void Game::set_number_of_rounds_to_play(int rounds) {
    number_of_rounds_to_play = rounds;
}

void Game::set_current_round_number(int round_num) {
    current_round_number = round_num;
}

// functions
void Game::play_a_round() {
    OPTIONS human_choice = human_player.read_choice();
    OPTIONS computer_choice = computer_player.make_choice();
    decide_round_winner(); // update the scores
    update_number_of_rounds(); /// update the round numbers
    set_current_round_number(get_current_round_number() + 1);
}

void Game::play_a_game() {
    // start with zero.
    set_current_round_number(0);
    human_player.set_current_round_number(0);
    computer_player.set_current_round_number(0);

    while(get_current_round_number() < get_number_of_rounds_to_play()) {
        play_a_round();
    }

    decide_game_winner(); // done with all the rounds, so announce the winner.
}


// helper functions
// OPTIONS::ROCK, PAPER, SCISSORS, DEFAULT_CHOICE
void Game::decide_round_winner() {

    OPTION h_choice, c_choice;
    h_choice = human_player.get_current_choice();
    c_choice = computer_player.get_current_choice();
    
    if ((h_choice == OPTIONS::DEFAULT_CHOICE) || (c_choice == OPTIONS::DEFAULT_CHOICE)) {
        cout << "Either you, or the computer, failed to make a choice from rock, paper & scissors. This round will not count towards the score." << endl;
        return; // return without updating the scores.
    }

    cout << "You entered " << h_choice << ", and the computer entered " << c_choice << endl;

    switch(c_choice)
    {
        case OPTIONS::ROCK:
            if (h_choice == OPTIONS::SCISSORS) {
                cout << "Computer won this round!" << endl;
                computer_player.set_current_score(get_current_score() + 1);
                return;
            }
            else if (h_choice == OPTIONS::PAPER) {
                cout << "You won this round!" << endl;
                human_player.set_current_score(get_current_score() + 1);
                return;
            }
            else {
                cout << "Draw!" << endl;
                return;
            }
            break;

        case OPTIONS::PAPER:
            if (h_choice == OPTIONS::ROCK) {
                cout << "Computer won this round!" << endl;
                computer_player.set_current_score(get_current_score() + 1);
                return;
            }

            else if (h_choice == OPTIONS::SCISSORS) {
                cout << "You won this round!" << endl;
                human_player.set_current_score(get_current_score() + 1);
                return;
            }
            else {
                cout << "Draw!" << endl;
                return;
            }
            break;

        case OPTIONS::SCISSORS:
            if (h_choice == OPTIONS::PAPER) {
                cout << "Computer won this round!" << endl;
                computer_player.set_current_score(get_current_score() + 1);
                return;
            }

            else if (h_choice == OPTIONS::ROCK) {
                cout << "You won this round!" << endl;
                human_player.set_current_score(get_current_score() + 1);
                return;
            }
            else {
                cout << "Draw!" << endl;
                return;
            }
            break;
        default: 
                cout << "You or the computer did not make a choice." << endl;
                return;    
    }

}
void Game::update_number_of_rounds() {
    human_player.set_number_of_rounds_played(get_number_of_rounds_played() + 1);
    computer_player.set_number_of_rounds_played(get_number_of_rounds_played() + 1);
}
void Game::decide_game_winner() {
    if (human_player.get_current_score() > computer_player.get_current_score()) {
        cout << "You've won the game!!" << endl;
    }

    else if (human_player.get_current_score() == computer_player.get_current_score()) {
        cout << "You and the computer have tied in the game!!" << endl;
    }

    else {
        cout << "You've lost the game!! Better luck next time." << endl;
    }
}
