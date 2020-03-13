//
// Created by Prajjwal Singhal on 2020-03-12.
//

#ifndef TESTPROGRAM_RANDOMCHOOSER_H
#define TESTPROGRAM_RANDOMCHOOSER_H

#include "Chooser.h"
class RandomChooser : public Chooser
{
public:
    OPTIONS make_choice(){
        return static_cast<OPTIONS>(rand()%3);
    }
};
#endif //TESTPROGRAM_RANDOMCHOOSER_H
