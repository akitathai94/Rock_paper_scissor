//
// Created by Prajjwal Singhal on 2020-03-12.
//

#ifndef TESTPROGRAM_CHOOSERFACTORY_H
#define TESTPROGRAM_CHOOSERFACTORY_H

#include "Chooser.h"
#include "MLChooser.h"
#include "RandomChooser.h"
#include "PlayerChooser.h"
class ChooserFactory{
public:
    Chooser *make_chooser(string which){
        if (which == "random") return new RandomChooser();
        else if (which == "ml") return new MLChooser();
        else if(which == "human") return new PlayerChooser();
        else return new RandomChooser();

    };
};
#endif //TESTPROGRAM_CHOOSERFACTORY_H
