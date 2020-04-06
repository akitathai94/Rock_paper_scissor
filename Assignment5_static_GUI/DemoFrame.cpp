\
#include "DemoFrame.h"

// The event table
wxBEGIN_EVENT_TABLE(DemoFrame, wxFrame)
    EVT_MENU(RPS_About, DemoFrame::on_about)
    EVT_MENU(RPS_Quit, DemoFrame::on_quit)
    EVT_MENU(RPS_CustomGame, DemoFrame::on_new_custom_game)
    EVT_MENU(RPS_DefaultGame, DemoFrame::on_new_default_game)
wxEND_EVENT_TABLE()

DemoFrame ::DemoFrame(wxWindow *parent, wxWindowID id, const wxString &title,
                        const wxPoint &pos, const wxSize &size,
                        long style, const wxString &name)
                      : wxFrame(parent, id, title, pos, size, style, name),
                        human_choice_panel(new HumanChoicePanel(this)),
                        round_number(new RoundNumber(this)),
                        computer_choice_panel(new ComputerChoicePanel(this)),
                        winner(new WinnerPanel(this)),
                        statistics_panel(new StatisticsPanel(this))
{
    // Adding the statusBar

    wxMenuBar *menuBar = new wxMenuBar();
    init_menu_bar(menuBar);
    SetMenuBar(menuBar);

    init_sizer();

    wxStatusBar *statusBar = new wxStatusBar(this);
    statusBar->SetStatusText("Welcome To Rock Paper Scissors Game");
    SetStatusBar(statusBar);

}

DemoFrame ::~DemoFrame() {}

void DemoFrame ::init_sizer()
{
    wxSizer *frame_sizer = new wxBoxSizer(wxVERTICAL);

    // Play button
    wxPanel *play_panel = new wxPanel(this, wxID_ANY);
    wxSizer *button_sizer = new wxBoxSizer(wxHORIZONTAL);
    wxButton *play_button = new wxButton(play_panel, wxID_ANY, "Play a Round");
    play_button->SetBackgroundColour(wxColour("#000000"));
    play_button->Bind     (wxEVT_BUTTON, &DemoFrame::on_play_a_round, this);
    button_sizer->Add(play_button, 0, 0, 0);
    button_sizer->AddSpacer(5);
    play_panel->SetSizer(button_sizer);

    frame_sizer->AddSpacer(20);
    frame_sizer->Add(play_panel, 0, wxALIGN_CENTER, 0);
    // the round number display place
    frame_sizer->AddSpacer(20);
    frame_sizer->Add(round_number, 0, wxALIGN_CENTER, 0);

    //the human input place
    frame_sizer->AddSpacer(20);
    frame_sizer->Add(human_choice_panel, 0, wxALIGN_CENTER, 0);

    //the computer choice output place
    frame_sizer->AddSpacer(20);
    frame_sizer->Add(computer_choice_panel, 0, wxALIGN_CENTER, 0);

    frame_sizer->AddSpacer(20);
    frame_sizer->Add(winner, 0, wxALIGN_CENTER, 0);

    frame_sizer->AddSpacer(20);
    frame_sizer->Add(statistics_panel, 0, wxALIGN_CENTER, 0);


    SetSizerAndFit(frame_sizer);
}
void DemoFrame ::init_menu_bar(wxMenuBar *menuBar)
{
    wxMenu *fileMenu = new wxMenu();
    fileMenu->Append(RPS_Quit,  "E&xit\tAlt-X", "Quit program");
    fileMenu->Append(RPS_About, "&About\tF1",   "Show about dialog");
    fileMenu->Append(RPS_DefaultGame, "&New Default Game", "Start new game");
    fileMenu->Append(RPS_CustomGame, "N&ew Custom Game", "Start new game");

    menuBar->Append(fileMenu, _("&File")); // & turns F into an accelarator
}

void DemoFrame ::on_about(wxCommandEvent &event)
{
    wxMessageBox(wxString::Format(
            "This is a RPS Game\n"),
                 "About the button demo",
                 wxOK | wxICON_INFORMATION,
                 this);
}
void DemoFrame::on_quit(wxCommandEvent& WXUNUSED(event))
{
    Close(true);  // true is to force the frame to close
}
void DemoFrame ::on_new_custom_game(wxCommandEvent &event)
{
    wxMessageBox(wxString::Format(
            "This will start a new custom Game\n"),
                 "Message",
                 wxOK | wxICON_INFORMATION,
                 this);
//    wxString test = human_choice_panel->get_chosen_button();
//    wxMessageBox(wxString::Format(
//            test),
//                 "Human Choice",
//                 wxOK | wxICON_INFORMATION,
//                 this);

}
void DemoFrame ::on_new_default_game(wxCommandEvent &event){
    wxMessageBox(wxString::Format(
            "This will start a new default Game\n"),
                 "About the button demo",
                 wxOK | wxICON_INFORMATION,
                 this);
}
void DemoFrame :: on_play_a_round(wxCommandEvent& event)
{
    round_number->update_current_round_number();
    computer_choice_panel->update_computer_choice_label("Rock", "Paper");
    statistics_panel->updateStatistics(1, 2, 3);
}