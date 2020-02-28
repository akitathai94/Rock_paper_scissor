#ifndef OPTION_RPS
#define OPTION_RPS
#include <iostream>
using namespace std;

enum OPTIONS{
            ROCK, PAPER, SCISSOR
        };

inline ostream& operator<<(ostream& ostr, const OPTIONS opt)
{
    switch(opt)
    {
        case OPTIONS::ROCK : ostr <<"ROCK"; break;
        case OPTIONS::PAPER: ostr <<"PAPER"; break;
        case OPTIONS::SCISSOR: ostr <<"SCISSOR"; break;
    }
    return ostr;
}

#endif
