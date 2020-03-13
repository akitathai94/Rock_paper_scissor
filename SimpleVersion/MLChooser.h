//
// Created by Prajjwal Singhal on 2020-03-12.
//

#ifndef TESTPROGRAM_MLCHOOSER_H
#define TESTPROGRAM_MLCHOOSER_H

#include "Chooser.h"
class MLChooser : public Chooser
{
public:
    OPTIONS make_choice(){
        return static_cast<OPTIONS>(rand()%3);
    }
};

#endif //TESTPROGRAM_MLCHOOSER_H
