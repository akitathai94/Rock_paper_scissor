//
// Created by Prajjwal Singhal on 2020-03-12.
//

#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "Player.h"
#include "OPTIONS.h"

int main(){
    srand ( time(NULL) );
    Player p1("human");
    OPTIONS var;
    int rock = 0, paper = 0, scissor = 0;
    for(int i = 0; i < 10; i++){
        var = p1.get_choice();
        switch (var){
            case OPTIONS::PAPER : paper++; break;
            case OPTIONS::ROCK : rock++; break;
            case OPTIONS::SCISSORS : scissor++; break;
        }
    }
    // Check to see if the the number of times each is chosen is random or not
    cout << "ROCK = " << rock << endl;
    cout << "PAPER = " << paper << endl;
    cout << "SCISSOR =" << scissor << endl;


    return 0;
}