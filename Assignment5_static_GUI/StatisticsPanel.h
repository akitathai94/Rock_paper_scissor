//
// Created by Prajjwal Singhal on 2020-04-05.
//

#ifndef ASSIGNMENT5_STATIC_GUI_STATISTICSPANEL_H
#define ASSIGNMENT5_STATIC_GUI_STATISTICSPANEL_H

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

class StatisticsPanel : public wxPanel
{
public:
    StatisticsPanel(wxFrame *parent) : wxPanel(parent, wxID_ANY)
    {   init();     }
    void updateStatistics(int h_wins, int c_wins, int t);

private:
    wxStaticText *human_wins;
    wxStaticText *computer_wins;
    wxStaticText *ties;
    void init();
};


#endif //ASSIGNMENT5_STATIC_GUI_STATISTICSPANEL_H
