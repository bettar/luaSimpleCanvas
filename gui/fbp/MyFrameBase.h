///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 4.2.1-0-g80c4cb6)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/gdicmn.h>
#include <wx/toolbar.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/sizer.h>
#include <wx/statusbr.h>
#include <wx/menu.h>
#include <wx/frame.h>
#include <wx/stattext.h>
#include <wx/panel.h>

///////////////////////////////////////////////////////////////////////////

#define wxID_MY_OPEN 6000
#define wxID_MY_EXPORT 6001
#define wxID_MY_ZOOM_IN 6002
#define wxID_MY_ZOOM_OUT 6003
#define wxID_MY_PAN_DOWN 6004
#define wxID_MY_PAN_UP 6005
#define wxID_MY_PAN_LEFT 6006
#define wxID_MY_PAN_RIGHT 6007
#define wxID_CELLO_STRINGS 6008
#define wxID_CELLO_MAJOR 6009
#define wxID_CELLO_MINOR 6010
#define wxID_GUITAR_MAJOR 6011

///////////////////////////////////////////////////////////////////////////////
/// Class MyFrameBase
///////////////////////////////////////////////////////////////////////////////
class MyFrameBase : public wxFrame
{
	DECLARE_EVENT_TABLE()
	private:

		// Private event handlers
		void _wxFB_OnToolClicked( wxCommandEvent& event ){ OnToolClicked( event ); }
		void _wxFB_OnMenuSelection( wxCommandEvent& event ){ OnMenuSelection( event ); }


	protected:
		wxToolBar* m_toolBar1;
		wxToolBarToolBase* m_toolOpen;
		wxToolBarToolBase* m_toolExport;
		wxToolBarToolBase* m_toolZoomIn;
		wxToolBarToolBase* m_toolZoomOut;
		wxToolBarToolBase* m_tool5;
		wxToolBarToolBase* m_tool6;
		wxToolBarToolBase* m_tool7;
		wxToolBarToolBase* m_tool8;
		wxStatusBar* m_statusBar1;
		wxMenuBar* m_menubar1;
		wxMenu* menuActions;
		wxMenu* menuCello;
		wxMenu* menuGuitar;

		// Virtual event handlers, override them in your derived class
		virtual void OnToolClicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnMenuSelection( wxCommandEvent& event ) { event.Skip(); }


	public:

		MyFrameBase( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,460 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~MyFrameBase();

};

///////////////////////////////////////////////////////////////////////////////
/// Class MyPanelBase
///////////////////////////////////////////////////////////////////////////////
class MyPanelBase : public wxPanel
{
	DECLARE_EVENT_TABLE()
	private:

		// Private event handlers
		void _wxFB_OnPaint( wxPaintEvent& event ){ OnPaint( event ); }


	protected:
		wxStaticText* m_staticText1;

		// Virtual event handlers, override them in your derived class
		virtual void OnPaint( wxPaintEvent& event ) { event.Skip(); }


	public:

		MyPanelBase( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,300 ), long style = wxTAB_TRAVERSAL, const wxString& name = wxEmptyString );

		~MyPanelBase();

};

