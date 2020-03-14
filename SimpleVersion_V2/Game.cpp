//
// Created by Prajjwal Singhal on 2020-02-28.
//

#include "Game.h"

Game :: Game() {
    no_of_player_wins = 0;
    no_of_computer_wins = 0;
    totalRounds = 5;
}
Game :: Game(int max_rounds){
    no_of_player_wins = 0;
    no_of_computer_wins = 0;
    totalRounds = max_rounds;
}
Game:: ~Game(){
    rounds.clear();
}
int Game ::get_current_round_no() {
    return rounds.size();
}

GAME_RESULT Game ::getCurrentRoundWinner(OPTIONS player_choice) {

    OPTIONS computer_choice = generateComputerChoiceRandom();

    Round r(player_choice, computer_choice);

    rounds.push_back(r);
    GAME_RESULT g = r.getWinner();

    switch(g)
    {
        case GAME_RESULT::PLAYER_WON : no_of_player_wins++; break;
        case GAME_RESULT::COMPUTER_WON: no_of_computer_wins++; break;
    }
    return g;
}

OPTIONS Game ::generateComputerChoiceRandom() {
    return static_cast<OPTIONS>(rand()%3);
}

GAME_RESULT Game :: getFinalGameWinner(){
    if(no_of_computer_wins > no_of_player_wins)
        return GAME_RESULT :: COMPUTER_WON;

    else if(no_of_player_wins > no_of_computer_wins)
        return GAME_RESULT :: PLAYER_WON;

    return GAME_RESULT :: DRAW;
}

OPTIONS Game :: getCurrentRoundComputerChoice(){
    return rounds[rounds.size()-1].get_computer_choice();
}
OPTIONS Game :: getCurrentRoundPlayerChoice(){
    return rounds[rounds.size()-1].get_player_choice();
}
OPTIONS Game :: getHumanChoice(){
    int choice;
    cout << "Enter your choice: ";
    cin >> choice;
    OPTIONS var;
    if(choice == 0)
        var = OPTIONS::ROCK;
    else if(choice == 1)
        var = OPTIONS::PAPER;
    else if(choice == 2)
        var = OPTIONS::SCISSORS;

    return var;
}
OPTIONS Game::generateComputerChoiceML() {
    map<string,int>::iterator max;
    OPTIONS choice;
    string current_game_pattern;
    int count_round = (int)rounds.size();
   // Return 4 recent choices to compare with pattern_line;
    if ( count_round >=2 ){
        // Read the last 4 choices from 2 rounds
        for(int i =(int)rounds.size() -2 ; i < rounds.size() ; i++){ current_game_pattern.push_back(enum_to_string(rounds[i].get_player_choice()));
            current_game_pattern.push_back(enum_to_string(rounds[i].get_computer_choice()));
        }
        // Find current_game_pattern if match dictionary
        string curr_S = current_game_pattern + "S";
        string curr_P = current_game_pattern + "P";
        string curr_R = current_game_pattern + "R";
        cout<<curr_S<<endl<<curr_P<<endl<<curr_R<<endl;
        auto pos_S = dict.find(curr_S);
        auto pos_P = dict.find(curr_P);
        auto pos_R = dict.find(curr_R);
        if(pos_S != dict.end() && pos_R != dict.end() && pos_P != dict.end()){
            choice = generateComputerChoiceRandom();
        } else if(pos_P != dict.end()) {
            int temp = pos_P->second;
            max = pos_P;
            if(pos_R != dict.end()){
                if (temp <= pos_R->second){
                    temp = pos_R->second;
                    max = pos_R;
                }
            } else if(pos_S != dict.end()){
                cout<<"Found pattern "<<curr_S<<endl;
                if ( temp <= pos_S->second){
                    temp = pos_S->second;
                    max = pos_S;
                }
            }
        cout<<"Found pattern "<<max->first<<endl;
        switch(max->first.back()){
            case 'S': choice = generateToWinChoice('S'); break;
            case 'R': choice = generateToWinChoice('R'); break;
            case 'P': choice = generateToWinChoice('P'); break;
        }
            max->second++;
            cout<<"Update Pattern "<<max->first<<" into freq "<<max->second<<endl;
    }
            
    } else  choice = generateComputerChoiceRandom();
    return choice;
}

OPTIONS Game::generateToWinChoice(char choice){
    if (choice == 'R'){
        return PAPER;
    } else if ( choice == 'P'){
        return SCISSORS;
    } else
        return ROCK;
}

void Game::loadFileToDict(){
    ifstream input;
   string pattern_line;
   string pattern;
   string num;
   int counter = 0;
   input.open("/Users/thaitruong/CMPE135/RPS/RPS/data.txt");
   if(input.fail()){
       cout<<"Cannot open the file:\n";
   }
    getline(input, pattern_line);
    for ( int i =0 ; i <= pattern_line.length() ; i++){
        if (isalpha(pattern_line[i])){
            counter++;
            if(counter <=5){
                pattern.push_back(pattern_line[i]);
            }
        } else if (isdigit(pattern_line[i])){
            num.push_back(pattern_line[i]);
        }
        else if(pattern_line[i] == ',' | i == pattern_line.length()){
            // reset cycle
            counter = 0;
            cout<<"Pattern is "<<pattern<<endl;
            cout<<"Num is "<<num<<endl;
            if(num != "")
            dict.insert(pair<string,int>(pattern,stoi(num)));
            pattern.clear();
            num.clear();
        }
    }
    input.close();
}

void Game::loadDicttoFile(){
    ofstream output;
    output.open("/Users/thaitruong/CMPE135/RPS/RPS/data.txt");
    for (auto itr = dict.begin() ; itr != dict.end() ; itr++){
       output<<itr->first;
        output<<":";
        output<<itr->second;
        output<<", ";
    }
    output.close();
    dict.erase(dict.begin(),dict.end());
}
