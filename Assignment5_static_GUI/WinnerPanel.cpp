//
// Created by Prajjwal Singhal on 2020-04-05.
//

#include "WinnerPanel.h"

void WinnerPanel :: init()
{
    wxSizer *main_panel_sizer = new wxBoxSizer(wxVERTICAL);

    wxPanel *winner_panel = new wxPanel(this, wxID_ANY);
    wxSizer *winner_sizer  = new wxGridSizer(2, 0, 5);
    wxStaticText *round_label =
            new wxStaticText(winner_panel, wxID_ANY, "Winner:");
    winner = new wxStaticText(winner_panel, wxID_ANY, "Nobody");
    winner->SetFont(winner->GetFont().Larger());

    winner_sizer->Add(round_label, 0, wxALIGN_RIGHT, 0);
    winner_sizer->Add(winner, 0, 0, 0);
    winner_panel->SetSizer(winner_sizer);

    main_panel_sizer->Add(winner_panel, 0, wxALIGN_CENTER, 0);
    main_panel_sizer->AddSpacer(20);

    SetSizer(main_panel_sizer);
}
void WinnerPanel ::update_winner(std::string name){
    winner->SetLabelText(name);
}