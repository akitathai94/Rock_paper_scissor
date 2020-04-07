
#include "Choice.h"

wxString choice_to_wxString(Choice choice)
{
    switch (choice)
    {
        case ROCK_GUI:      return "Rock";
        case PAPER_GUI:     return "Paper";
        case SCISSORS_GUI:  return "Scissor";
        default:        return "None";
    }
}