#ifndef OPTION_RPS
#define OPTION_RPS
#include <iostream>
#include <string>
using namespace std;

enum OPTIONS{
        // Same reason as GameResult class
            ROCK, PAPER, SCISSORS
        };

inline ostream& operator<<(ostream& ostr, const OPTIONS opt)
{
    switch(opt)
    {
        case OPTIONS::ROCK : ostr <<"Rock"; break;
        case OPTIONS::PAPER: ostr <<"Paper"; break;
        case OPTIONS::SCISSORS: ostr <<"Scissors"; break;
    }
    return ostr;
}
inline char enum_to_string(OPTIONS opt){
    switch(opt){
        case ROCK : return 'R'; break;
        case PAPER : return 'P'; break;
        case SCISSORS : return 'S'; break;
    }
}
#endif
