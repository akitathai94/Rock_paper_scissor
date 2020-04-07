//
// Created by Prajjwal Singhal on 2020-04-05.
//

#ifndef ASSIGNMENT5_STATIC_GUI_WINNERPANEL_H
#define ASSIGNMENT5_STATIC_GUI_WINNERPANEL_H

#include <wx/wxprec.h>

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

class WinnerPanel : public wxPanel
{
public:
    WinnerPanel(wxFrame *parent) : wxPanel(parent, wxID_ANY)
    {   init();     }
    void update_winner(std::string name);
private:
    wxStaticText *winner;
    void init();
};


#endif //ASSIGNMENT5_STATIC_GUI_WINNERPANEL_H
