//#include "Game.h"
//
//#define MAX_ROUNDS_IN_GAME = 20;
//// constructors
//
//// default constructor
//Game::Game() {
//    human_player = new Human();
//    computer_player = new Computer();
//    number_of_rounds_to_play = MAX_ROUNDS_IN_GAME; // default value
//    current_round_number = -1; // default value
//}
//
//// parameterized constructor
//// parameter specifies number of rounds to play in the game.
//Game::Game(Human h_player, Computer c_player, int rounds = MAX_ROUNDS_IN_GAME) {
//    human_player = h_player;
//    computer_player = c_player;
//    number_of_rounds_to_play = rounds; // use custom value if provided
//    current_round_number = -1; // default value
//}
//// mutators
//void Game::set_number_of_rounds_to_play(int rounds) {
//    number_of_rounds_to_play = rounds;
//}
//
//void Game::set_current_round_number(int round_num) {
//    current_round_number = round_num;
//}
//
//// functions
//void Game::play_a_round() {
//    OPTIONS human_choice = human_player.read_choice();
//    OPTIONS computer_choice = computer_player.make_choice();
//    decide_round_winner(); // update the scores
//    update_number_of_rounds(); /// update the round numbers
//    set_current_round_number(get_current_round_number() + 1);
//}
//
//void Game::play_a_game() {
//    // start with zero.
//    set_current_round_number(0);
//    human_player.set_current_round_number(0);
//    computer_player.set_current_round_number(0);
//
//    while(get_current_round_number() < get_number_of_rounds_to_play()) {
//        play_a_round();
//    }
//
//    decide_game_winner(); // done with all the rounds, so announce the winner.
//}
//
//// helper functions
//// OPTIONS::ROCK, PAPER, SCISSORS, DEFAULT_CHOICE
//void Game::decide_round_winner() {
//
//    OPTION h_choice, c_choice;
//    h_choice = human_player.get_current_choice();
//    c_choice = computer_player.get_current_choice();
//
//    if ((h_choice == OPTIONS::DEFAULT_CHOICE) || (c_choice == OPTIONS::DEFAULT_CHOICE)) {
//        cout << "Either you, or the computer, failed to make a choice from rock, paper & scissors. This round will not count towards the score." << endl;
//        return; // return without updating the scores.
//    }
//
//    cout << "You entered " << h_choice << ", and the computer entered " << c_choice << endl;
//
//    switch(c_choice)
//    {
//        case OPTIONS::ROCK:
//            if (h_choice == OPTIONS::SCISSORS) {
//                cout << "Computer won this round!" << endl;
//                computer_player.set_current_score(get_current_score() + 1);
//                return;
//            }
//            else if (h_choice == OPTIONS::PAPER) {
//                cout << "You won this round!" << endl;
//                human_player.set_current_score(get_current_score() + 1);
//                return;
//            }
//            else {
//                cout << "Draw!" << endl;
//                return;
//            }
//            break;
//
//        case OPTIONS::PAPER:
//            if (h_choice == OPTIONS::ROCK) {
//                cout << "Computer won this round!" << endl;
//                computer_player.set_current_score(get_current_score() + 1);
//                return;
//            }
//
//            else if (h_choice == OPTIONS::SCISSORS) {
//                cout << "You won this round!" << endl;
//                human_player.set_current_score(get_current_score() + 1);
//                return;
//            }
//            else {
//                cout << "Draw!" << endl;
//                return;
//            }
//            break;
//
//        case OPTIONS::SCISSORS:
//            if (h_choice == OPTIONS::PAPER) {
//                cout << "Computer won this round!" << endl;
//                computer_player.set_current_score(get_current_score() + 1);
//                return;
//            }
//
//            else if (h_choice == OPTIONS::ROCK) {
//                cout << "You won this round!" << endl;
//                human_player.set_current_score(get_current_score() + 1);
//                return;
//            }
//            else {
//                cout << "Draw!" << endl;
//                return;
//            }
//            break;
//        default:
//                cout << "You or the computer did not make a choice." << endl;
//                return;
//    }
//
//}
//void Game::update_number_of_rounds() {
//    human_player.set_number_of_rounds_played(get_number_of_rounds_played() + 1);
//    computer_player.set_number_of_rounds_played(get_number_of_rounds_played() + 1);
//}
//void Game::decide_game_winner() {
//    if (human_player.get_current_score() > computer_player.get_current_score()) {
//        cout << "You've won the game!!" << endl;
//    }
//
//    else if (human_player.get_current_score() == computer_player.get_current_score()) {
//        cout << "You and the computer have tied in the game!!" << endl;
//    }
//
//    else {
//        cout << "You've lost the game!! Better luck next time." << endl;
//    }
//}

#include "Game.h"



Game ::Game(int total_rounds, string humanAlgo, string compAlgo) {
    human = new Player(humanAlgo);
    computer = new Player(compAlgo);
    humanWins = computerWins = 0;
    totalRounds = total_rounds;
}

GAME_RESULT Game ::get_game_winner() {
    if(humanWins > computerWins)            return GAME_RESULT :: PLAYER_WON;
    else if(humanWins == computerWins)      return GAME_RESULT :: DRAW;
    else                                    return GAME_RESULT :: COMPUTER_WON;

}

GAME_RESULT Game ::get_round_winner(int round_number) {
    return rounds[round_number].getWinner();
}

GAME_RESULT Game ::get_last_round_winner() {
    return get_round_winner(rounds.size() - 1);
}

OPTIONS Game ::get_human_choice(int round_number) {
    return rounds[round_number].get_player_choice();
}

OPTIONS Game ::get_computer_choice(int round_number) {
    return rounds[round_number].get_computer_choice();
}

OPTIONS Game ::get_last_human_choice() {
    return get_human_choice(rounds.size() - 1);
}

OPTIONS Game ::get_last_computer_choice() {
    return get_computer_choice(rounds.size() - 1);
}

int Game ::get_current_computer_score() {
    return computerWins;
}
int Game ::get_current_human_score() {
    return humanWins;
}

GAME_RESULT Game::play_a_round() {
    OPTIONS human_choice = human->get_choice();
    OPTIONS computer_choice = computer->get_choice();
    Round r(human_choice, computer_choice);
    rounds.push_back(r);

    GAME_RESULT round_winner = r.getWinner();

    if      (round_winner == GAME_RESULT::COMPUTER_WON)  computerWins++;
    else if (round_winner == GAME_RESULT::PLAYER_WON)    humanWins++;

    return round_winner;

}

GAME_RESULT Game ::play_full_game() {
    for(int i = 0; i < totalRounds; i++){
        GAME_RESULT round_winner = play_a_round();
        print_results(cout, get_last_human_choice(), get_last_computer_choice(), round_winner, i+1);
    }

    return get_game_winner();
}
void Game ::print_results(ostream& out,OPTIONS humanChoice, OPTIONS compChoice, GAME_RESULT winner, int round_number){
    out << "Round " << round_number << " Result" << endl;
    out << "You chose: " << humanChoice << endl;
    out << "Computer Chose: " << compChoice << endl;
    out << winner << endl << endl;
}