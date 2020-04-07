//
// Created by Prajjwal Singhal on 2020-04-05.
//

#ifndef ASSIGNMENT5_STATIC_GUI_HUMANCHOICEPANEL_H
#define ASSIGNMENT5_STATIC_GUI_HUMANCHOICEPANEL_H

#include "Choice.h"
using namespace std;
class HumanChoicePanel : public wxPanel
{
public:
    HumanChoicePanel(wxFrame *parent) : wxPanel(parent, wxID_ANY)
    {   init();     }

    // Functions to handles the clicking of different buttons
    void on_rock(wxCommandEvent& event);
    void on_paper(wxCommandEvent& event);
    void on_scissors(wxCommandEvent& event);

    wxString get_chosen_button();
private:
    wxStaticText *chosen_button_name;

    void init();
    void update_button_choice_text(const Choice choice);
};


#endif //ASSIGNMENT5_STATIC_GUI_HUMANCHOICEPANEL_H
