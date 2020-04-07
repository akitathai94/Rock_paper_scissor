#include "Game.h"



Game ::Game(int total_rounds, CHOOSER_TYPE humanAlgo, CHOOSER_TYPE compAlgo, int n) {
    human = new Player(humanAlgo);
    computer = new Player(compAlgo);
    computer_algo = compAlgo;
    humanWins = computerWins = 0;
    totalRounds = total_rounds;
    N = n;
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
int Game :: get_number_of_rounds_played()
{
    return rounds.size();
}
GAME_RESULT Game::play_a_round() {
    OPTIONS human_choice = human->get_choice(rounds, N);
    OPTIONS computer_choice =computer->get_choice(rounds, N);


    Round r(human_choice, computer_choice);
    rounds.push_back(r);

    GAME_RESULT round_winner = r.getWinner();

    if      (round_winner == GAME_RESULT::COMPUTER_WON)  computerWins++;
    else if (round_winner == GAME_RESULT::PLAYER_WON)    humanWins++;

    return round_winner;

}
GAME_RESULT Game::play_a_round(OPTIONS human_choice) {
    OPTIONS computer_choice =computer->get_choice(rounds, N);


    Round r(human_choice, computer_choice);
    rounds.push_back(r);

    GAME_RESULT round_winner = r.getWinner();

    if      (round_winner == GAME_RESULT::COMPUTER_WON)  computerWins++;
    else if (round_winner == GAME_RESULT::PLAYER_WON)    humanWins++;

    return round_winner;

}
bool Game :: is_game_finished()
{
    if(get_number_of_rounds_played() >= totalRounds)
        return true;
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
