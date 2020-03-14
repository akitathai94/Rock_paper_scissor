//
// Created by Prajjwal Singhal on 2020-03-12.
//

#ifndef TESTPROGRAM_MLCHOOSER_H
#define TESTPROGRAM_MLCHOOSER_H

#include "Chooser.h"
#include "Round.h"
#include "OPTIONS.h"
#include <unordered_map>
#include <vector>

class MLChooser : public Chooser
{
public:
    //OPTIONS make_choice();
    OPTIONS make_choice(vector<Round> );

private:
    unordered_map<string, int> past_patterns_and_freq;
    void update_ml_algorithm(vector<Round> );
};

#endif //TESTPROGRAM_MLCHOOSER_H
