#include "ComputerChoicePanel.h"

void ComputerChoicePanel ::init()
{
    wxSizer *main_panel_sizer = new wxBoxSizer(wxVERTICAL);

    wxPanel *computerTextPanel = new wxPanel(this, wxID_ANY);
    wxSizer *computerTextSizer = new wxGridSizer(2, 0, 5);
    wxStaticText *computer_text = new wxStaticText(computerTextPanel, wxID_ANY, "Computer");
    computerTextSizer->Add(computer_text, 0, 0, 0);
    computerTextPanel->SetSizer(computerTextSizer);

    // Predicted Choice Panel
    wxPanel *predicted_choice_panel = new wxPanel (this, wxID_ANY);
    wxSizer *predicted_choice_sizer  = new wxGridSizer(2, 0, 5);
    wxStaticText *predicted_human_label =
            new wxStaticText(predicted_choice_panel, wxID_ANY, "Predicted human choice:");
    predicted_human_choice = new wxStaticText(predicted_choice_panel, wxID_ANY, "human predicted choice here");
    predicted_human_choice->SetFont(predicted_human_choice->GetFont().Larger());

    predicted_choice_sizer->Add(predicted_human_label, 0, wxALIGN_RIGHT, 0);
    predicted_choice_sizer->Add(predicted_human_choice, 0, 0, 0);
    predicted_choice_panel->SetSizer(predicted_choice_sizer);

    // Computer Choice Panel
    wxPanel *computer_choice_panel = new wxPanel (this, wxID_ANY);
    wxSizer *computer_choice_sizer  = new wxGridSizer(2, 0, 5);
    wxStaticText *computer_label =
            new wxStaticText(computer_choice_panel, wxID_ANY, "Therefore computer chooses:");
    computer_choice = new wxStaticText(computer_choice_panel, wxID_ANY, "computer choice here");
    computer_choice->SetFont(computer_choice->GetFont().Larger());

    computer_choice_sizer->Add(computer_label, 0, wxALIGN_RIGHT, 0);
    computer_choice_sizer->Add(computer_choice, 0, 0, 0);
    computer_choice_panel->SetSizer(computer_choice_sizer);

    // Main Panel
    main_panel_sizer->Add(computerTextPanel, 0, wxALIGN_CENTER, 0);
    main_panel_sizer->AddSpacer(15);
    main_panel_sizer->Add(predicted_choice_panel, 0, wxALIGN_CENTER, 0);
    main_panel_sizer->AddSpacer(10);
    main_panel_sizer->Add(computer_choice_panel, 0, wxALIGN_CENTER, 0);
    main_panel_sizer->AddSpacer(10);

    SetSizer(main_panel_sizer);
}

void ComputerChoicePanel :: update_computer_choice_label(std::string p_choice, std::string c_choice)
{
    computer_choice->SetLabelText(c_choice);
    predicted_human_choice->SetLabelText(p_choice);
}