//
// Created by Prajjwal Singhal on 2020-03-12.
//

#ifndef TESTPROGRAM_CHOOSER_H
#define TESTPROGRAM_CHOOSER_H

#include "OPTIONS.h"
#include "Round.h"
class Chooser{
public:
    //virtual OPTIONS make_choice() = 0;
    virtual OPTIONS make_choice(vector<Round> rounds, int N) = 0;
};
#endif //TESTPROGRAM_CHOOSER_H
