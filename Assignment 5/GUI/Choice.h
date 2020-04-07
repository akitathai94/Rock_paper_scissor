//
// Created by Prajjwal Singhal on 2020-04-05.
//

#ifndef ASSIGNMENT5_STATIC_GUI_CHOICE_H
#define ASSIGNMENT5_STATIC_GUI_CHOICE_H

#include <wx/wxprec.h>

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

typedef int Choice;

enum {ROCK_GUI, PAPER_GUI, SCISSORS_GUI, NONE_GUI};

wxString choice_to_wxString(Choice choice);

#endif //ASSIGNMENT5_STATIC_GUI_CHOICE_H
