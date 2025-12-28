///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 4.2.1-0-g80c4cb6)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "MyFrameBase.h"

///////////////////////////////////////////////////////////////////////////

BEGIN_EVENT_TABLE( MyFrameBase, wxFrame )
	EVT_TOOL( wxID_MY_OPEN, MyFrameBase::_wxFB_OnToolClicked )
	EVT_TOOL( wxID_MY_EXPORT, MyFrameBase::_wxFB_OnToolClicked )
	EVT_TOOL( wxID_MY_ZOOM_IN, MyFrameBase::_wxFB_OnToolClicked )
	EVT_TOOL( wxID_MY_ZOOM_OUT, MyFrameBase::_wxFB_OnToolClicked )
	EVT_TOOL( wxID_MY_PAN_DOWN, MyFrameBase::_wxFB_OnToolClicked )
	EVT_TOOL( wxID_MY_PAN_UP, MyFrameBase::_wxFB_OnToolClicked )
	EVT_TOOL( wxID_MY_PAN_LEFT, MyFrameBase::_wxFB_OnToolClicked )
	EVT_TOOL( wxID_MY_PAN_RIGHT, MyFrameBase::_wxFB_OnToolClicked )
	EVT_MENU( wxID_EXIT, MyFrameBase::_wxFB_OnMenuSelection )
	EVT_MENU( wxID_ABOUT, MyFrameBase::_wxFB_OnMenuSelection )
	EVT_MENU( wxID_CELLO_STRINGS, MyFrameBase::_wxFB_OnMenuSelection )
	EVT_MENU( wxID_CELLO_MAJOR, MyFrameBase::_wxFB_OnMenuSelection )
	EVT_MENU( wxID_CELLO_MINOR, MyFrameBase::_wxFB_OnMenuSelection )
	EVT_MENU( wxID_GUITAR_MAJOR, MyFrameBase::_wxFB_OnMenuSelection )
END_EVENT_TABLE()

MyFrameBase::MyFrameBase( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );

	m_toolBar1 = new wxToolBar( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTB_HORIZONTAL|wxTB_TEXT );
	m_toolOpen = m_toolBar1->AddTool( wxID_MY_OPEN, wxT("Open"), wxArtProvider::GetBitmap( wxASCII_STR(wxART_FILE_OPEN), wxASCII_STR(wxART_TOOLBAR) ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxT("Refresh"), NULL );

	m_toolExport = m_toolBar1->AddTool( wxID_MY_EXPORT, wxT("Export"), wxArtProvider::GetBitmap( wxASCII_STR(wxART_FILE_SAVE), wxASCII_STR(wxART_TOOLBAR) ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxT("Export to PNG"), NULL );

	m_toolBar1->AddSeparator();

	m_toolZoomIn = m_toolBar1->AddTool( wxID_MY_ZOOM_IN, wxT("Zoom In"), wxArtProvider::GetBitmap( wxASCII_STR(wxART_PLUS), wxASCII_STR(wxART_TOOLBAR) ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL );

	m_toolZoomOut = m_toolBar1->AddTool( wxID_MY_ZOOM_OUT, wxT("Zoom Out"), wxArtProvider::GetBitmap( wxASCII_STR(wxART_MINUS), wxASCII_STR(wxART_TOOLBAR) ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL );

	m_toolBar1->AddSeparator();

	m_tool5 = m_toolBar1->AddTool( wxID_MY_PAN_DOWN, wxT("Down"), wxArtProvider::GetBitmap( wxASCII_STR(wxART_GO_DOWN), wxASCII_STR(wxART_TOOLBAR) ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL );

	m_tool6 = m_toolBar1->AddTool( wxID_MY_PAN_UP, wxT("Up"), wxArtProvider::GetBitmap( wxASCII_STR(wxART_GO_UP), wxASCII_STR(wxART_TOOLBAR) ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL );

	m_tool7 = m_toolBar1->AddTool( wxID_MY_PAN_LEFT, wxT("Left"), wxArtProvider::GetBitmap( wxASCII_STR(wxART_GO_BACK), wxASCII_STR(wxART_TOOLBAR) ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL );

	m_tool8 = m_toolBar1->AddTool( wxID_MY_PAN_RIGHT, wxT("Right"), wxArtProvider::GetBitmap( wxASCII_STR(wxART_GO_FORWARD), wxASCII_STR(wxART_TOOLBAR) ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL );

	m_toolBar1->Realize();

	bSizer1->Add( m_toolBar1, 0, wxEXPAND, 5 );


	this->SetSizer( bSizer1 );
	this->Layout();
	m_statusBar1 = this->CreateStatusBar( 1, wxSTB_SIZEGRIP, wxID_ANY );
	m_menubar1 = new wxMenuBar( 0 );
	menuActions = new wxMenu();
	wxMenuItem* miQuit;
	miQuit = new wxMenuItem( menuActions, wxID_EXIT, wxString( wxT("Quit") ) , wxEmptyString, wxITEM_NORMAL );
	menuActions->Append( miQuit );

	wxMenuItem* m_menuAbout;
	m_menuAbout = new wxMenuItem( menuActions, wxID_ABOUT, wxString( wxT("About") ) , wxEmptyString, wxITEM_NORMAL );
	menuActions->Append( m_menuAbout );

	wxMenuItem* m_menuExport;
	m_menuExport = new wxMenuItem( menuActions, wxID_MY_EXPORT, wxString( wxT("Export") ) , wxEmptyString, wxITEM_NORMAL );
	menuActions->Append( m_menuExport );

	m_menubar1->Append( menuActions, wxT("Actions") );

	menuCello = new wxMenu();
	wxMenuItem* miDiagram;
	miDiagram = new wxMenuItem( menuCello, wxID_CELLO_STRINGS, wxString( wxT("String Diagram") ) , wxEmptyString, wxITEM_NORMAL );
	menuCello->Append( miDiagram );

	wxMenuItem* miCelloMajor;
	miCelloMajor = new wxMenuItem( menuCello, wxID_CELLO_MAJOR, wxString( wxT("Major scale") ) , wxEmptyString, wxITEM_NORMAL );
	menuCello->Append( miCelloMajor );

	wxMenuItem* miCelloMinor;
	miCelloMinor = new wxMenuItem( menuCello, wxID_CELLO_MINOR, wxString( wxT("Minor scales") ) , wxEmptyString, wxITEM_NORMAL );
	menuCello->Append( miCelloMinor );

	m_menubar1->Append( menuCello, wxT("Cello") );

	menuGuitar = new wxMenu();
	wxMenuItem* miGtMajor;
	miGtMajor = new wxMenuItem( menuGuitar, wxID_GUITAR_MAJOR, wxString( wxT("Major scale") ) , wxEmptyString, wxITEM_NORMAL );
	menuGuitar->Append( miGtMajor );

	m_menubar1->Append( menuGuitar, wxT("Guitar") );

	this->SetMenuBar( m_menubar1 );


	this->Centre( wxBOTH );
}

MyFrameBase::~MyFrameBase()
{
}

BEGIN_EVENT_TABLE( MyPanelBase, wxPanel )
	EVT_LEFT_DOWN( MyPanelBase::_wxFB_OnLeftDown )
	EVT_LEFT_UP( MyPanelBase::_wxFB_OnLeftUp )
	EVT_MOTION( MyPanelBase::_wxFB_OnMotion )
	EVT_PAINT( MyPanelBase::_wxFB_OnPaint )
	EVT_RIGHT_DOWN( MyPanelBase::_wxFB_OnRightDown )
	EVT_RIGHT_UP( MyPanelBase::_wxFB_OnRightUp )
END_EVENT_TABLE()

MyPanelBase::MyPanelBase( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style, const wxString& name ) : wxPanel( parent, id, pos, size, style, name )
{
	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxVERTICAL );

	m_staticText1 = new wxStaticText( this, wxID_ANY, wxT("This is wxStaticText"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1->Wrap( -1 );
	bSizer2->Add( m_staticText1, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );


	this->SetSizer( bSizer2 );
	this->Layout();
}

MyPanelBase::~MyPanelBase()
{
}
