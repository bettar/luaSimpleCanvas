// Alex Bettarini - 16 Dec 2025
#include <wx/wx.h>

#include "main.h"
#include "MyFrame.h"

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit()
{
    if ( !wxApp::OnInit() )
        return false;

    // Logging stuff
    {
        wxLog::DisableTimestamp();
#ifdef __linux__
        std::cout << "Sharp ♯" << std::endl; // ok
#else
        wxLog::SetActiveTarget(new wxLogStderr); // error and warning in Xcode Output pane
#endif
       
#ifndef NDEBUG
        wxLog::SetLogLevel(wxLOG_Trace); // trace debug info status message warning=2 error=1
#else
        wxLog::SetLogLevel(wxLOG_Warning);
#endif

        wxLogMessage("%s, line %d", __FUNCTION__, __LINE__);
#ifndef __linux__
        wxLogWarning("%s, line %d", __FUNCTION__, __LINE__); // Linux GUI popup
#endif
        wxLogDebug("wxWidgets %s", wxVERSION_STRING);
    }

    wxImage::AddHandler(new wxPNGHandler);
    
    auto frame = new MyFrame(nullptr);
    frame->Show(true);
#if 1
    frame->SetFocus();
    frame->Raise();
#endif
    return true;
}
