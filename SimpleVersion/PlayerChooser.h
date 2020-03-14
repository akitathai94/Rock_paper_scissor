//
// Created by Prajjwal Singhal on 2020-03-12.
//

#ifndef TESTPROGRAM_PLAYERCHOOSER_H
#define TESTPROGRAM_PLAYERCHOOSER_H

#include "Chooser.h"
#include "Round.h"
#include <vector>
class PlayerChooser : public Chooser
{
public:
    OPTIONS make_choice(vector<Round> rounds){
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;
        return static_cast<OPTIONS>(choice%3);;
    }
};
#endif //TESTPROGRAM_PLAYERCHOOSER_H
