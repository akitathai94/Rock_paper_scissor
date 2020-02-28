#include <iostream>
#include <string>
#include <cstdlib>
#include "OPTION.h"
#include "Game.h"
#include "Player.h"

using namespace std;


int main(){
    const int ROUNDS = 20;
    Game gameplay;
    srand (time(NULL));
       int human_choice;
       int machine_choice;
    do {
           gameplay.start_round();
           cout<<"Input your choice for game "<< gameplay.get__round_count()+1<<" th :\n";
           cout << "Choices" << endl;
           cout << "0 = Rock" << endl;
           cout << "1 = Paper" << endl;
           cout << "2 = Scissor" << endl;
           cout <<"Score are Human "<<gameplay.get__human_result()<<" "<<"Machine "<<gameplay.get__machine_result()<<"\n";
           cin >>  human_choice;
           machine_choice = rand() % 2 + 0;
           gameplay.set__round_players_choice(human_choice, machine_choice);
           if(gameplay.is__draw()){
               gameplay.set__next_round();
           } else {
               gameplay.is_roundWinner();
               gameplay.set__next_round();
           }
           if(gameplay.get__round_count() == ROUNDS){
            gameplay.set__game_Over(true);
            cout <<"Score are Human "<<gameplay.get__human_result()<<" "<<"Machine "<<gameplay.get__machine_result()<<"\n";
            gameplay.is_gameWinner();
            
           }
    }while(!gameplay.game_is_Over());
    return 0;
}
