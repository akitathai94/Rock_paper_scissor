//
// Created by Prajjwal Singhal on 2020-04-05.
//

#ifndef ASSIGNMENT5_STATIC_GUI_COMPUTERCHOICEPANEL_H
#define ASSIGNMENT5_STATIC_GUI_COMPUTERCHOICEPANEL_H

#include <wx/wxprec.h>

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

class ComputerChoicePanel : public wxPanel
{
public:
    ComputerChoicePanel(wxFrame *parent) : wxPanel(parent, wxID_ANY)
    {   init();     }
    void update_computer_choice_label(std::string p_choice, std::string c_choice);

private:
    wxStaticText *predicted_human_choice;
    wxStaticText *computer_choice;
    void init();
};


#endif //ASSIGNMENT5_STATIC_GUI_COMPUTERCHOICEPANEL_H
