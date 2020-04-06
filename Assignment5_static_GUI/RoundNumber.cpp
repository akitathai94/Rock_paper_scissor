//
// Created by Prajjwal Singhal on 2020-04-05.
//

#include "RoundNumber.h"

void RoundNumber :: init()
{
    current_round_number = 0;
    wxSizer *main_panel_sizer = new wxBoxSizer(wxVERTICAL);

    wxPanel *choice_panel = new wxPanel(this, wxID_ANY);
    wxSizer *choice_sizer  = new wxGridSizer(2, 0, 5);
    wxStaticText *round_label =
            new wxStaticText(choice_panel, wxID_ANY, "Round:");
    current_round_text = new wxStaticText(choice_panel, wxID_ANY, std::to_string(0));
    current_round_text->SetFont(current_round_text->GetFont().Larger());

    choice_sizer->Add(round_label, 0, wxALIGN_RIGHT, 0);
    choice_sizer->Add(current_round_text, 0, 0, 0);
    choice_panel->SetSizer(choice_sizer);

    main_panel_sizer->Add(choice_panel, 0, wxALIGN_CENTER, 0);
    main_panel_sizer->AddSpacer(20);

    SetSizer(main_panel_sizer);
}

void RoundNumber ::update_current_round_number()
{
    current_round_number++;
    current_round_text->SetLabelText(std::to_string(current_round_number));
}