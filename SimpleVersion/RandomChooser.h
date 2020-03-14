//
// Created by Prajjwal Singhal on 2020-03-12.
//

#ifndef TESTPROGRAM_RANDOMCHOOSER_H
#define TESTPROGRAM_RANDOMCHOOSER_H

#include "Chooser.h"
#include "Round.h"
#include <vector>

class RandomChooser : public Chooser
{
public:
    OPTIONS make_choice(vector<Round> rounds, int N){
        return static_cast<OPTIONS>(rand()%3);
    }
};
#endif //TESTPROGRAM_RANDOMCHOOSER_H
