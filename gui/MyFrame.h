// Alex Bettarini - 16 Dec 2025
#pragma once

#include "MyFrameBase.h"
#include "MyPanel.h"

extern "C" {
#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"
}

class MyFrame : public MyFrameBase
{
    MyPanel* myPanel;
    lua_State *L = nullptr;
    
	protected:
		// Handlers for MyFrame2 events.
		void OnToolClicked( wxCommandEvent& event );
		void OnMenuSelection( wxCommandEvent& event );

    void OnQuit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);

    void OpenScript();

public:
    MyFrame( wxWindow* parent );
    virtual ~MyFrame();
};

