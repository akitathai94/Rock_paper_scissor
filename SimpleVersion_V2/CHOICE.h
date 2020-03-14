//
//  CHOICE.h
//  RPS
//
//  Created by Thai Truong on 3/11/20.
//  Copyright © 2020 Thai Truong. All rights reserved.
//

#ifndef CHOICE_h
#define CHOICE_h
#include <iostream>
using namespace std;
enum CHOICES {
    ML, RANDOM
};

inline ostream& operator<<(ostream& ostr, const CHOICES choice){
    switch(choice){
        case CHOICES::ML : ostr<<"Machine Learning";break;
        case CHOICES::RANDOM : ostr<<"Random";break;
    }
    return ostr;
}

#endif /* CHOICE_h */
