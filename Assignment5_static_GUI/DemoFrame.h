
#pragma once
#include <wx/wxprec.h>

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include "HumanChoicePanel.h"
#include "RoundNumber.h"
#include "ComputerChoicePanel.h"
#include "WinnerPanel.h"
#include "StatisticsPanel.h"

class DemoFrame : public wxFrame
{
public:
    DemoFrame(wxWindow *parent,
              wxWindowID id,
              const wxString& title,
              const wxPoint& pos = wxDefaultPosition,
              const wxSize& size = wxDefaultSize,
              long style = wxDEFAULT_FRAME_STYLE,
              const wxString& name = wxFrameNameStr);
    ~DemoFrame();

    void on_about(wxCommandEvent& event);
    void on_quit(wxCommandEvent& event);
    void on_new_default_game(wxCommandEvent& event);
    void on_new_custom_game(wxCommandEvent& event);
    void on_play_a_round(wxCommandEvent& event);

private:
    wxDECLARE_EVENT_TABLE();

    wxPanel *play_panel;
    RoundNumber *round_number;
    HumanChoicePanel *human_choice_panel;
    ComputerChoicePanel *computer_choice_panel;
    WinnerPanel *winner;
    StatisticsPanel *statistics_panel;

    void init_menu_bar(wxMenuBar *menu);
    void init_sizer();



    // Panels
    // 1. Round number display
    // 2. Human Choice input Display
    // 3. Computer choice output display
    // 4. The winner display
    // 5. Statistics  Display

};

// IDs for the menu commands.
enum
{
    RPS_About = wxID_ABOUT,
    RPS_Quit  = wxID_EXIT,
    RPS_DefaultGame = wxID_HIGHEST + 1,
    RPS_CustomGame = wxID_HIGHEST + 2
};