#include "MainApp.h"
#include "DemoFrame.h"
#include "id.h"

IMPLEMENT_APP(MainApp); // Creates Instance of our app class

MainApp :: MainApp()
{}
bool MainApp ::OnInit()
{
    if(!wxApp::OnInit())
        return false;

    DemoFrame *frame = new DemoFrame(NULL,window::MAINWINDOW , "Rock Paper Scissor: 20 rounds/game");
    frame->Show();
    return true;
}

MainApp :: ~MainApp()
{}