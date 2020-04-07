
#include "DemoFrame.h"

OPTIONS get_losing_choice(OPTIONS choice);

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
    reset_the_display();
    current_game = nullptr;
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
    if(current_game != nullptr)
    {
        delete current_game;
        current_game = nullptr;
    }

    wxMessageBox(wxString::Format(
            "This will start a new custom Game\n"),
                 "Alert",
                 wxOK | wxICON_INFORMATION,
                 this);


    wxTextEntryDialog dlg(this, "Enter the number of rounds you want to play", "Test");
    dlg.ShowModal();
    wxString number_of_rounds = dlg.GetValue();

    current_game = new Game(wxAtoi(number_of_rounds), CHOOSER_TYPE::RANDOM, CHOOSER_TYPE::ML, 5);
    set_game_start_display();

}
void DemoFrame ::on_new_default_game(wxCommandEvent &event){

    if(current_game != nullptr)
    {
        delete current_game;
        current_game = nullptr;
    }

    wxMessageBox(wxString::Format(
            "This will start a new default Game\n"),
                 "Alert",
                 wxOK | wxICON_INFORMATION,
                 this);
    current_game = new Game(20, CHOOSER_TYPE::RANDOM, CHOOSER_TYPE::ML, 5);
    set_game_start_display();

}
void DemoFrame :: on_play_a_round(wxCommandEvent& event)
{
    if(current_game->is_game_finished())
    {
        on_game_end();
        return;
    }
    SetStatusText("Currently Playing a Game");
    wxString human_choice_wxString = human_choice_panel->get_chosen_button();
    OPTIONS human_choice = wxString_to_OPTIONS(human_choice_wxString);

    current_game->play_a_round(human_choice);

    round_number->update_current_round_number(current_game->get_number_of_rounds_played());

    OPTIONS comp_made_choice = current_game->get_last_computer_choice();
    OPTIONS hum_pred_choice = get_losing_choice(comp_made_choice);
    computer_choice_panel->update_computer_choice_label(OPTIONS_to_wxString(hum_pred_choice), OPTIONS_to_wxString(comp_made_choice));

    winner->update_winner(GAMEResult_to_wxString(current_game->get_last_round_winner()));

    int human_wins = current_game->get_current_human_score();
    int comp_wins = current_game->get_current_computer_score();
    int ties = current_game->get_number_of_rounds_played() - (human_wins + comp_wins);
    statistics_panel->updateStatistics(human_wins, comp_wins, ties);

    if(current_game->is_game_finished())
    {
        on_game_end();
        return;
    }

}
void DemoFrame :: on_game_end()
{
    string w = GAMEResult_to_wxString(current_game->get_game_winner());
    wxString winner = w + "Won The Game";
    wxMessageBox(wxString::Format(
            winner),
                 "GAME RESULT",
                 wxOK | wxICON_INFORMATION,
                 this);


    reset_the_display();

}
void DemoFrame :: set_game_start_display()
{
    round_number->update_current_round_number(0);
    computer_choice_panel->update_computer_choice_label("Play a Round", "Play a Round");
    winner->update_winner("Play a Round");
    statistics_panel->updateStatistics(0, 0, 0);
    SetStatusText("Play a Round");
}
void DemoFrame ::reset_the_display()
{
    round_number->update_current_round_number(0);
    computer_choice_panel->update_computer_choice_label("Start a New Game", "Start a New Game");
    winner->update_winner("Start a new Game");
    statistics_panel->updateStatistics(0, 0, 0);
    SetStatusText("Start a new Game");

}
OPTIONS DemoFrame :: wxString_to_OPTIONS(wxString human_choice_wxString)
{
    if      (human_choice_wxString == "Rock")       return OPTIONS :: ROCK;
    else if (human_choice_wxString == "Paper")      return OPTIONS :: PAPER;
    else if (human_choice_wxString == "Scissor")    return OPTIONS :: SCISSORS;
    else                                            return OPTIONS :: ROCK;
}
string DemoFrame :: OPTIONS_to_wxString(OPTIONS option)
{
    switch (option)
    {
        case OPTIONS::ROCK :        return "Rock";
        case OPTIONS::PAPER:        return "Paper";
        case OPTIONS::SCISSORS:     return "Scissors";
        default:                    return "Error";
    }
}

string DemoFrame ::GAMEResult_to_wxString(GAME_RESULT result)
{
    switch(result)
    {
        case GAME_RESULT :: PLAYER_WON      :          return "Human     ";
        case GAME_RESULT :: COMPUTER_WON    :          return "Computer  ";
        case GAME_RESULT :: DRAW            :          return "Draw      ";
        default                             :          return "Error     ";
    }
}

OPTIONS get_losing_choice(OPTIONS choice)
{
    switch (choice)
    {
        case OPTIONS::ROCK :        return OPTIONS::SCISSORS;
        case OPTIONS::PAPER:        return OPTIONS::ROCK;
        case OPTIONS::SCISSORS:     return OPTIONS::PAPER;
        default:                    return OPTIONS::PAPER;
    }
}
