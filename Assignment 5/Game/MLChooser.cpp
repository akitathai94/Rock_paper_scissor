//
// Created by Prajjwal Singhal on 2020-03-13.
//

#include "MLChooser.h"

string enum_to_string(OPTIONS choice);
OPTIONS string_to_enum(string code);
string get_N_choices(vector<Round> rounds, int pos, int no_of_iteration);

//OPTIONS MLChooser ::make_choice(){
//    return static_cast<OPTIONS>(rand()%3);
//}

OPTIONS MLChooser ::make_choice(vector<Round> rounds, int N) {
    // if there isn't enough data to make ml prediction
    if(rounds.size() < ((N/2) + 1))
        return static_cast<OPTIONS>(rand()%3);

    update_ml_algorithm(rounds, N); // to add the pattern for the last round

    string current_game_pattern = get_N_choices(rounds, rounds.size() - (N/2), N/2);

    string curr_s = current_game_pattern + "S";
    string curr_r = current_game_pattern + "R";
    string curr_p = current_game_pattern + "P";
    // R R P S S R (PSSRR, PSSRP, PSSRS)
    // R R P S S R P R S P S P R
    // Remove this
    //cout << "Current Pattern is: " << current_game_pattern;

    int freq_s = 0, freq_p = 0, freq_r = 0;
    auto pos_s = past_patterns_and_freq.find(curr_s);   // search all 3
    auto pos_r = past_patterns_and_freq.find(curr_r);
    auto pos_p = past_patterns_and_freq.find(curr_p);

    if(pos_s != past_patterns_and_freq.end())
        freq_s = pos_s->second;
    if(pos_r != past_patterns_and_freq.end())
        freq_r = pos_r->second;
    if(pos_p != past_patterns_and_freq.end())
        freq_p = pos_p->second;

    //  if there is no matching pattern
    if(freq_p == 0 && freq_r == 0 && freq_s == 0)     return static_cast<OPTIONS>(rand()%3);

    // get the pattern with max freq
    if(freq_s >= freq_r && freq_s >= freq_p)            return string_to_enum("R");
    else if(freq_r >= freq_s && freq_r >= freq_p)    return string_to_enum("P");
    else if(freq_p >= freq_s && freq_p >= freq_r)    return string_to_enum("S");

    // In case something is wrong with if statements and no if statement works
    return string_to_enum("P");
}

void MLChooser ::update_ml_algorithm(vector<Round> rounds, int N) {

    string current_pattern = get_N_choices(rounds, rounds.size() - ((N/2) + 1), N/2);
    current_pattern += enum_to_string(rounds[rounds.size()-1].get_player_choice());

    if(past_patterns_and_freq.find(current_pattern) == past_patterns_and_freq.end()){
        past_patterns_and_freq.insert(pair<string, int> (current_pattern, 1));
    }
    else
        past_patterns_and_freq.find(current_pattern)->second++;


}
string enum_to_string(OPTIONS choice){
    switch(choice){
        case OPTIONS::SCISSORS: return "S";
        case OPTIONS::PAPER:    return "P";
        case OPTIONS::ROCK:     return "R";
    }
}
OPTIONS string_to_enum(string code){
    if(code == "P")         return OPTIONS :: PAPER;
    else if(code == "R")    return OPTIONS :: ROCK;
    else                    return OPTIONS :: SCISSORS;
}

string get_N_choices(vector<Round> rounds, int pos, int no_of_iteration){

    string current_game_pattern;
    OPTIONS var;
    for(int i = 0; i < no_of_iteration; i++){
        var = rounds[pos+i].get_player_choice();
        current_game_pattern += enum_to_string(var);
        var = rounds[pos+i].get_computer_choice();
        current_game_pattern += enum_to_string(var);
    }
    return current_game_pattern;
}