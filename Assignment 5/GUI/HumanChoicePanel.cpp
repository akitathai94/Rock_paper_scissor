//
// Created by Prajjwal Singhal on 2020-04-05.
//

#include "HumanChoicePanel.h"

void HumanChoicePanel :: init()
{
    wxSizer *main_panel_sizer = new wxBoxSizer(wxVERTICAL);

    // Human Text Panel
    wxPanel *humanTextPanel = new wxPanel(this, wxID_ANY);
    wxSizer *humanTextSizer = new wxGridSizer(2, 0, 5);
    wxStaticText *human_text = new wxStaticText(humanTextPanel, wxID_ANY, "Human");
    humanTextSizer->Add(human_text, 0, 0, 0);
    humanTextPanel->SetSizer(humanTextSizer);

    // Button Panel
    wxPanel *button_panel = new wxPanel(this, wxID_ANY);
    wxSizer *button_sizer = new wxBoxSizer(wxHORIZONTAL);
    wxStaticText *chosen_text = new wxStaticText(button_panel, wxID_ANY, "Choose:");

    wxButton *rock_button = new wxButton(button_panel, wxID_ANY,
                                            choice_to_wxString(ROCK_GUI));
    wxButton *paper_button = new wxButton(button_panel, wxID_ANY,
                                         choice_to_wxString(PAPER_GUI));
    wxButton *scissors_button = new wxButton(button_panel, wxID_ANY,
                                         choice_to_wxString(SCISSORS_GUI));

    rock_button->SetBackgroundColour(wxColour("#000000"));
    paper_button->SetBackgroundColour(wxColour("#000000"));
    scissors_button->SetBackgroundColour(wxColour("#000000"));

    rock_button->Bind     (wxEVT_BUTTON, &HumanChoicePanel::on_rock, this);
    paper_button->Bind    (wxEVT_BUTTON, &HumanChoicePanel::on_paper, this);
    scissors_button->Bind (wxEVT_BUTTON, &HumanChoicePanel::on_scissors, this);

    button_sizer->Add(chosen_text, 0, 0, 0);
    button_sizer->AddSpacer(5);
    button_sizer->Add(rock_button, 0, 0, 0);
    button_sizer->AddSpacer(5);
    button_sizer->Add(paper_button, 0, 0, 0);
    button_sizer->AddSpacer(5);
    button_sizer->Add(scissors_button, 0, 0, 0);
    button_panel->SetSizer(button_sizer);

    // Choice Panel
    wxPanel *choice_panel = new wxPanel (this, wxID_ANY);
    wxSizer *choice_sizer  = new wxGridSizer(2, 0, 5);
    wxStaticText *chosen_object_label =
            new wxStaticText(choice_panel, wxID_ANY, "Human Chooses:");
    chosen_button_name = new wxStaticText(choice_panel, wxID_ANY, "Rock");
    chosen_button_name->SetFont(chosen_button_name->GetFont().Larger());

    choice_sizer->Add(chosen_object_label, 0, wxALIGN_RIGHT, 0);
    choice_sizer->Add(chosen_button_name, 0, 0, 0);
    choice_panel->SetSizer(choice_sizer);

    // Main Panel
    main_panel_sizer->Add(humanTextPanel, 0, wxALIGN_CENTER, 0);
    main_panel_sizer->AddSpacer(20);
    main_panel_sizer->Add(button_panel, 0, wxALIGN_CENTER, 0);
    main_panel_sizer->AddSpacer(20);
    main_panel_sizer->Add(choice_panel, 0, wxALIGN_CENTER, 0);
    main_panel_sizer->AddSpacer(20);

    SetSizer(main_panel_sizer);

}

void HumanChoicePanel :: on_rock(wxCommandEvent& event)
{
    update_button_choice_text(ROCK_GUI);
}

void HumanChoicePanel :: on_paper(wxCommandEvent& event)
{
    update_button_choice_text(PAPER_GUI);
}

void HumanChoicePanel :: on_scissors(wxCommandEvent& event)
{
    update_button_choice_text(SCISSORS_GUI);
}

void HumanChoicePanel ::update_button_choice_text(const Choice choice)
{
    chosen_button_name->SetLabelText(choice_to_wxString(choice));
}
wxString HumanChoicePanel :: get_chosen_button()
{
    return chosen_button_name->GetLabelText();
}