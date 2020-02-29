#ifndef OPTION_RPS
#define OPTION_RPS
#include <iostream>
using namespace std;

enum OPTIONS {
            ROCK, PAPER, SCISSORS, DEFAULT_CHOICE
};

inline ostream& operator<<(ostream& ostr, const OPTIONS opt) {
    switch(opt)
    {
        case OPTIONS::ROCK : ostr <<"ROCK"; break;
        case OPTIONS::PAPER: ostr <<"PAPER"; break;
        case OPTIONS::SCISSORS: ostr <<"SCISSORS"; break;
        case OPTIONS::DEFAULT_CHOICE: ostr <<"DEFAULT_CHOICE"; break;
    }
    return ostr;
}

#endif