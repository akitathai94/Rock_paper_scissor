//
// Created by Prajjwal Singhal on 2020-04-05.
//

#include "StatisticsPanel.h"

void StatisticsPanel :: init()
{
    wxSizer *main_panel_sizer = new wxBoxSizer(wxVERTICAL);

    // Statics logo
    wxPanel *statistics_panel = new wxPanel(this, wxID_ANY);
    wxSizer *statistics_text_sizer = new wxGridSizer(2, 0, 5);
    wxStaticText *statistics_text = new wxStaticText(statistics_panel, wxID_ANY, "Statistics");
    statistics_text_sizer->Add(statistics_text, 0, 0, 0);
    statistics_panel->SetSizer(statistics_text_sizer);

    //human wins line
    wxPanel *human_wins_panel = new wxPanel (this, wxID_ANY);
    wxSizer *human_wins_sizer  = new wxGridSizer(2, 0, 5);
    wxStaticText *human_wins_label =
            new wxStaticText(human_wins_panel, wxID_ANY, "Human Wins:");
    human_wins = new wxStaticText(human_wins_panel, wxID_ANY, "0");
    human_wins->SetFont(human_wins->GetFont().Larger());

    human_wins_sizer->Add(human_wins_label, 0, wxALIGN_RIGHT, 0);
    human_wins_sizer->Add(human_wins, 0, 0, 0);
    human_wins_panel->SetSizer(human_wins_sizer);

    //computer wins line
    wxPanel *computer_wins_panel = new wxPanel (this, wxID_ANY);
    wxSizer *computer_wins_sizer  = new wxGridSizer(2, 0, 5);
    wxStaticText *computer_wins_label =
            new wxStaticText(computer_wins_panel, wxID_ANY, "Computer Wins:");
    computer_wins = new wxStaticText(computer_wins_panel, wxID_ANY, "0");
    computer_wins->SetFont(computer_wins->GetFont().Larger());

    computer_wins_sizer->Add(computer_wins_label, 0, wxALIGN_RIGHT, 0);
    computer_wins_sizer->Add(computer_wins, 0, 0, 0);
    computer_wins_panel->SetSizer(computer_wins_sizer);

    //Ties line
    wxPanel *ties_panel = new wxPanel (this, wxID_ANY);
    wxSizer *ties_sizer  = new wxGridSizer(2, 0, 5);
    wxStaticText *ties_label =
            new wxStaticText(ties_panel, wxID_ANY, "Ties:");
    ties = new wxStaticText(ties_panel, wxID_ANY, "0");
    ties->SetFont(ties->GetFont().Larger());

    ties_sizer->Add(ties_label, 0, wxALIGN_RIGHT, 0);
    ties_sizer->Add(ties, 0, 0, 0);
    ties_panel->SetSizer(ties_sizer);

    // Main panel
    main_panel_sizer->Add(statistics_panel, 0, wxALIGN_CENTER, 0);
    main_panel_sizer->AddSpacer(15);
    main_panel_sizer->Add(human_wins_panel, 0, wxALIGN_CENTER, 0);
    main_panel_sizer->AddSpacer(10);
    main_panel_sizer->Add(computer_wins_panel, 0, wxALIGN_CENTER, 0);
    main_panel_sizer->AddSpacer(10);
    main_panel_sizer->Add(ties_panel, 0, wxALIGN_CENTER, 0);
    main_panel_sizer->AddSpacer(10);

    SetSizer(main_panel_sizer);
}

void StatisticsPanel :: updateStatistics(int h_wins, int c_wins, int t)
{
    human_wins->SetLabel(std::to_string(h_wins));
    computer_wins->SetLabel(std::to_string(c_wins));
    ties->SetLabel(std::to_string(t));
}