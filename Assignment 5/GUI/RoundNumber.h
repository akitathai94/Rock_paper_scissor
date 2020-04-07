//
// Created by Prajjwal Singhal on 2020-04-05.
//

#ifndef ASSIGNMENT5_STATIC_GUI_ROUNDNUMBER_H
#define ASSIGNMENT5_STATIC_GUI_ROUNDNUMBER_H

#include <wx/wxprec.h>

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

class RoundNumber : public wxPanel
{
public:
    RoundNumber(wxFrame *parent) : wxPanel(parent, wxID_ANY)
    {   init();     }
    void update_current_round_number(int n);
private:
    wxStaticText *current_round_text;
    int current_round_number;
    void init();
};


#endif //ASSIGNMENT5_STATIC_GUI_ROUNDNUMBER_H
