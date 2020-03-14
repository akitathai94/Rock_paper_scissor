//
//  Interface.cpp
//  RPS
//
//  Created by Thai Truong on 3/11/20.
//  Copyright © 2020 Thai Truong. All rights reserved.
//
#include "Interface.h"
Chooser* ChooserFactory::make_chooser(CHOICES choice){
    if(choice == RANDOM)
        return new RandomChooser();
    else if (choice == ML)
        return new MLChooser();
    return new Chooser();
}
OPTIONS RandomChooser::make_choice(){
    return static_cast<OPTIONS>(rand()%3);
}

OPTIONS MLChooser::make_choice(){
    int num_rounds = get_current_round_no(); // get current round
    if(num_rounds <= 2)
        return Game::generateComputerChoiceRandom();
    else {
        return Game::generateComputerChoiceML();
    }
}
