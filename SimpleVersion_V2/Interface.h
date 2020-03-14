//
//  Interface.h
//  RPS
//
//  Created by Thai Truong on 3/11/20.
//  Copyright © 2020 Thai Truong. All rights reserved.
//

#ifndef Interface_h
#define Interface_h
#include "CHOICE.h"
#include "Game.h"
#include "OPTIONS.h"
class Chooser : public Game {
public:
    Chooser(){Game();};
    virtual OPTIONS make_choice(){return ROCK;};
};

class ChooserFactory {
public:
    static Chooser* make_chooser(CHOICES choice);
};

class RandomChooser : public Chooser {
public:
    RandomChooser(){};
    OPTIONS make_choice();
};

class MLChooser : public Chooser {
public:
    MLChooser(){};
    OPTIONS make_choice();
};


#endif /* Interface_h */


