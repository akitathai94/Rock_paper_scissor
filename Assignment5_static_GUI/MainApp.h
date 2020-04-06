#pragma once
#include <wx/wxprec.h>

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

class MainApp : public wxApp
{
public:
    MainApp();
    bool OnInit();
    ~MainApp();
};

DECLARE_APP(MainApp); // gives a convienience function wxGetApp() which return an App instance

