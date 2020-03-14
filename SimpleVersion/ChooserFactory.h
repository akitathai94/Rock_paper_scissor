//
// Created by Prajjwal Singhal on 2020-03-12.
//

#ifndef TESTPROGRAM_CHOOSERFACTORY_H
#define TESTPROGRAM_CHOOSERFACTORY_H

#include "Chooser.h"
#include "MLChooser.h"
#include "RandomChooser.h"
#include "PlayerChooser.h"
#include "ChooserType.h"

class ChooserFactory {
public:
    Chooser *make_chooser(CHOOSER_TYPE which){
        if (which == CHOOSER_TYPE::RANDOM) return new RandomChooser();
        else if (which == CHOOSER_TYPE::ML) return new MLChooser();
        else if(which == CHOOSER_TYPE::HUMAN) return new PlayerChooser();
        else return new RandomChooser();

    };
};
#endif //TESTPROGRAM_CHOOSERFACTORY_H
