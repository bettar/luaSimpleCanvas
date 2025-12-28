// Alex Bettarini - 2025
#include "wx/wx.h"
#include "wx/log.h"

#include "MyFrame.h"
#include "MyPanel.h"

int say_hello(lua_State *L) {
    printf("Hello from C!\n");
    return 0; // Number of return values
}

static int l_sin (lua_State *L)
{
     double d = lua_tonumber(L, 1);  /* get argument */
     lua_pushnumber(L, sin(d));  /* push result */
     return 1;  /* number of results */
}

MyFrame::MyFrame( wxWindow* parent )
: MyFrameBase( parent )
{
    SetTitle(wxTheApp->GetAppName() + "😀🎼"); // 𝄞

    //wxLogMessage("%s:%d %s", __FILE_NAME__, __LINE__, __FUNCTION__);
    myPanel = new MyPanel(this);
    GetSizer()->Add( myPanel, 1, wxEXPAND|wxALL, 0 );
    
    L = luaL_newstate();
    luaL_openlibs(L);

#if 1 // Step 4: calling C functions from Lua
    lua_register(L, "say_hello", say_hello); // Register C function in Lua
    luaL_dostring(L, "say_hello()\n"); // Call C function from Lua
#endif

#if 1    // Passing data between C and Lua
    lua_pushnumber(L, 42); // Push a variable to Lua
    lua_setglobal(L, "x");

    luaL_dostring(L, "print('Value from C: ', x)"); // Run Lua code
#endif

#if 1
    // https://www.lua.org/pil/26.1.html
    lua_pushcfunction(L, l_sin);
    lua_setglobal(L, "mysin"); // test with fourth.lua
#endif
}

MyFrame::~MyFrame()
{
    lua_close(L);
}

void MyFrame::OnToolClicked( wxCommandEvent& event )
{
    auto id = event.GetId();

    switch (id)
    {
        case wxID_ABOUT:
            OnAbout(event);
            break;
            
        case wxID_MY_OPEN:
            OpenScript();
            break;

        case wxID_MY_EXPORT:
            myPanel->OnExport();
            break;

        case wxID_EXIT:
            OnQuit(event);
            break;

        case wxID_MY_ZOOM_IN:
            myPanel->OnZoomIn();
            break;
            
        case wxID_MY_ZOOM_OUT:
            myPanel->OnZoomOut();
            break;
            
        case wxID_MY_PAN_DOWN:
            myPanel->OnPanDown();
            myPanel->Refresh();
            break;

        case wxID_MY_PAN_UP:
            myPanel->OnPanUp();
            myPanel->Refresh();
            break;
        
        case wxID_MY_PAN_LEFT:
            myPanel->OnPanLeft();
            myPanel->Refresh();
            break;
            
        case wxID_MY_PAN_RIGHT:
            myPanel->OnPanRigth();
            myPanel->Refresh();
            break;
            
        case wxID_CELLO_STRINGS:
            myPanel->whatToDraw = DRAW_STRING_DIAGRAM;
            myPanel->Refresh();
            break;
            
        case wxID_CELLO_MAJOR:
            myPanel->whatToDraw = DRAW_MAJOR_SCALE;
            myPanel->Refresh();
            break;
            
        case wxID_CELLO_MINOR:
            myPanel->whatToDraw = DRAW_MINOR_SCALE;
            myPanel->Refresh();
            break;
            
        default:
            wxLogMessage("%s:%d %s, TODO: %d", __FILE_NAME__, __LINE__, __FUNCTION__, id);
            break;
    }
}

void MyFrame::OnMenuSelection( wxCommandEvent& event )
{
    auto id = event.GetId();
    wxLogMessage("%s:%d %s, %d", __FILE_NAME__, __LINE__, __FUNCTION__,
                 id);
    OnToolClicked(event);
}

void MyFrame::OnQuit(wxCommandEvent& WXUNUSED(event))
{
    // true is to force the frame to close
    Close(true);
}

void MyFrame::OpenScript()
{
    wxLogMessage("%s:%d %s", __FILE_NAME__, __LINE__, __FUNCTION__);
    std::cout <<  __FILE_NAME__ << __LINE__ << __FUNCTION__ << std::endl;
    wxFileDialog dlg = wxFileDialog(
        nullptr,
        _("Choose a Lua File"),
        wxEmptyString, // defaultDir
        wxEmptyString,
        "All Files (*.*)|*.*|"
        "Lua File (*.lua)|*.lua",
        wxFD_OPEN | wxFD_FILE_MUST_EXIST | wxFD_CHANGE_DIR,
        wxDefaultPosition);

    if (dlg.ShowModal() != wxID_OK)
        return;

    auto filename = dlg.GetPath();
    auto justFilename = wxFileName(filename).GetFullName();
    
    // 70
    wxLogDebug("%s Reading: %s", __FUNCTION__, filename);
    std::cout <<  "Reading " << justFilename << std::endl;
    
    int status = luaL_dofile(L, filename);
    if (status != LUA_OK) {
        wxLogError("Error: %s", lua_tostring(L, -1));
    }

#if 1 // Step 3: Calling Lua functions from C
    if (justFilename == "script.lua") {
        wxLogMessage("%s:%d %s", __FILE_NAME__, __LINE__, __FUNCTION__);
        std::cout << "filename " << filename << std::endl;

        lua_getglobal(L, "add"); // or "mathlib"
        if (lua_istable(L, -1))  // module
        {
            lua_getfield(L, -1, "add"); // get the add function from mathlib
            // push
            // push
            // pcall
            // lua_tonumber(L, -1

        }
        else if (lua_isfunction(L, -1))
        {
            // lua_call(L, 0, 0);  // Call the function with no arguments
            // lua_call(L, 1, 0);  // Call the function with 1 argument, no return value
            // lua_call(L, 0, 1);  // Call the function with no argument, expect 1 return value
            lua_pushnumber(L, 10);
            lua_pushnumber(L, 20);
            if (lua_pcall(L,2,1,0) != LUA_OK) // 2 arguments, 1 return value
            {
                std::cout << "error " << lua_tostring(L, -1) << std::endl;
            }
            else  {
                if (lua_isnumber(L, -1))
                    std::cout << "Result from Lua: " << lua_tonumber(L, -1) << std::endl;
            }
        }

    }
#endif

}

void MyFrame::OnAbout(wxCommandEvent& WXUNUSED(event))
{
    wxLogMessage("%s:%d %s", __FILE_NAME__, __LINE__, __FUNCTION__);
    
    wxMessageBox(wxString::Format
                 (
                    "Welcome to %s!\n"
                    "\n"
                    "This is %s\n"
                    "running under %s.",
                    wxVERSION_STRING,
                    wxTheApp->GetAppName(),
                    wxGetOsDescription()
                 ),
                 wxString::Format("About %s", wxTheApp->GetAppName()),
                 wxOK | wxICON_INFORMATION,
                 this);
}

