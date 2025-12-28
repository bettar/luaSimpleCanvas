// Alex Bettarini - 16 Dec 2025
#include <memory>

#include "wx/wx.h"
#include "wx/log.h"
#include "wx/dcgraph.h"
#include "wx/dcbuffer.h"

#include "MyPanel.h"
#include "engineWx.h"

#include "diag1b.h"
#include "maj_arp.h"

MyPanel::MyPanel( wxWindow* parent )
: MyPanelBase( parent )
{
    wxLogMessage("%s:%d %s", __FILE_NAME__, __LINE__, __FUNCTION__);
}

void MyPanel::OnExport()
{
    exportRequest = true;
    Refresh();
#if 0
    auto tempBmp = DrawContents(GetClientSize());
    if (tempBmp.IsOk()) {
        wxString fn("screenshot5.png");
        tempBmp.SaveFile(fn, wxBITMAP_TYPE_PNG);
        wxLogMessage("%s:%d %s, saved as %s", __FILE_NAME__, __LINE__, __FUNCTION__, fn);
    }
#endif
}

wxBitmap DrawContents2(const wxSize size)
{
    wxLogMessage("%s:%d %s (%d,%d) (%d,%d)", __FILE_NAME__, __LINE__, __FUNCTION__, 0,0,size.x,size.y);

    wxMemoryDC memDC;
    HPGL::engineWx engine(&memDC);
    
    // TODO: draw from Lua
    
    return engine._bmp;
}

// (0,0) is top-left
wxBitmap MyPanel::DrawContents(const wxSize size)// wxDC& dcUnused )
{
    wxLogMessage("%s:%d %s (%d,%d) (%d,%d)", __FILE_NAME__, __LINE__, __FUNCTION__, 0,0,size.x,size.y);
#ifndef NDEBUG
    const wxSize sizeC = GetClientSize();
    wxLogMessage("Client size (%d,%d)", sizeC.x, sizeC.y);
#endif

    wxMemoryDC memDC;
    //memDC.SetMapMode(wxMM_METRIC); // big canvas. Ogni unità logica è 1 millimetro._memDC->SetMapMode(wxMM_METRIC);
    HPGL::engineWx engine(&memDC);

    switch (whatToDraw) {
        case DRAW_STRING_DIAGRAM:
            doDiag1b(engine);
            break;
            
        case DRAW_MAJOR_SCALE:
            do_major_stuff(3,4,engine);
            break;
            
        default:
            break;
    }

#ifndef NDEBUG
    const wxSize sizeD = engine._bmp.GetSize();
    wxLogMessage("wxbitmap size (%d,%d)", sizeD.x, sizeD.y);
#endif

    return engine._bmp;
}

void MyPanel::OnPaint( wxPaintEvent& event )
{
    wxLogMessage("%s:%d %s", __FILE_NAME__, __LINE__, __FUNCTION__);
    wxPaintDC pdc(this);
    PrepareDC(pdc); // Adjust scrolled contents.

#if 0
    wxGCDC gdc;
    {
        m_renderer = wxGraphicsRenderer::GetDefaultRenderer();
        
        auto context = m_renderer->CreateContext(pdc);
        context->SetAntialiasMode(m_useAntiAliasing ? wxANTIALIAS_DEFAULT : wxANTIALIAS_NONE);
        
        gdc.SetBackground(GetBackgroundColour());
        gdc.SetGraphicsContext(context);
    }

    //gdc.SetTransformMatrix(m_affineMatrix);
    gdc.SetUserScale( zoom,zoom);
    gdc.DrawBitmap(DrawContents(GetClientSize()), 0, 0);
#else
    std::unique_ptr<wxGraphicsContext> gc(wxGraphicsContext::Create(pdc));
    
    const wxSize size = GetClientSize();
  #ifdef NDEBUG
    const wxDouble margin = 0;
  #else
    const wxDouble margin = 10;
    gc->PushState();
    
    // from sample "shaped"
    const double h = size.y / 3.0;

    wxGraphicsPath path = gc->CreatePath();
    path.AddRectangle(0, 0, size.x, h);
    gc->SetBrush(wxBrush(wxColour(0, 0, 255, wxALPHA_OPAQUE)));
    gc->FillPath(path);
    
    gc->SetBrush(wxBrush(wxColour(0, 0, 255, wxALPHA_OPAQUE / 2)));
    gc->Translate(0, h);
    gc->FillPath(path);

    // This blue won't actually be seen and instead the white background will
    // be visible, because this brush is fully transparent.
    gc->SetBrush(wxBrush(wxColour(0, 0, 255, wxALPHA_TRANSPARENT)));
    gc->Translate(0, h);
    gc->FillPath(path);
    
    gc->PopState();
  #endif

    //gdc.SetTransformMatrix(m_affineMatrix);
    gc->PushState();
    gc->Scale(zoom,zoom);
    wxBitmap tempBmp;
    if (whatToDraw != DRAW_NOTHING) {
        tempBmp = DrawContents(GetClientSize());
        bwidth = tempBmp.GetWidth();
        bheight = tempBmp.GetHeight();
        
        // Center the image
        auto width = size.GetWidth();
        auto height = size.GetHeight();
        auto transx = this->pan[0] + (width  - this->bwidth  * this->zoom) / (2*this->zoom);
        auto transy = this->pan[1] + (height - this->bheight * this->zoom) / (2*this->zoom);
     
        gc->Translate(transx, transy);
        gc->DrawBitmap(tempBmp,
                       margin, margin,
                       this->bwidth - 2*margin,
                       this->bheight - 2*margin);
    }
    gc->PopState(); // Restore the translation and scaling
#endif
    
#if 1
    if (exportRequest)
    {
        exportRequest = false;
        #if 0 // ng
        wxBitmap bmp;
        gc->CreateBitmap(bmp);
        if (bmp.IsOk()) {
            wxImage img = bmp.ConvertToImage();
            img.SaveFile("screenshot6.png", wxBITMAP_TYPE_PNG);
        }
        #else
        if (tempBmp.IsOk()) {
            wxString fn("screenshot5.png");
            tempBmp.SaveFile(fn, wxBITMAP_TYPE_PNG);
            wxLogMessage("%s:%d %s, saved as %s", __FILE_NAME__, __LINE__, __FUNCTION__, fn);
        }
        #endif
    }
#endif
}

void MyPanel::OnZoomIn()
{
    zoom *= 1.1f;
    Refresh();
}

void MyPanel::OnZoomOut()
{
    if (zoom > 1) {
        zoom /= 1.1f;
        Refresh();
    }
}

void MyPanel::OnPanUp()
{
    pan[1] -= 30;
}

void MyPanel::OnPanDown()
{
    pan[1] += 30;
}

void MyPanel::OnPanLeft()
{
    pan[0] -= 30;
}


void MyPanel::OnPanRigth()
{
    pan[0] += 30;
}

void MyPanel::OnLeftDown( wxMouseEvent& event )
{
    this->mousepos = event.GetPosition();
}

void MyPanel::OnLeftUp( wxMouseEvent& event )
{
    this->SetCursor(wxCursor(wxCURSOR_DEFAULT));
}

void MyPanel::OnRightDown( wxMouseEvent& event )
{
    this->mousepos = event.GetPosition();
}

void MyPanel::OnRightUp( wxMouseEvent& event )
{
    this->SetCursor(wxCursor(wxCURSOR_DEFAULT));
}

void MyPanel::OnMotion( wxMouseEvent& evt )
{
    if (evt.LeftIsDown()) {
        this->OnLeftIsDown(evt);
        this->SetCursor(wxCursor(wxCURSOR_SIZING));
    }
    else if (evt.RightIsDown()) {
        this->OnRightIsDown(evt);

        if (wxPlatformIs(wxOS_WINDOWS))
        {
#if 1
            wxLogDebug("%s %d, TODO: custom cursor", __FUNCTION__, __LINE__);
#else
            // Custom cursors with > 2 colors only works on Windows currently
            image = wxImage(util::GetResourcePath("contrast_high.png"));
            this->SetCursor(wxCursorFromImage(image));
#endif
        }
    }

    this->mousepos = evt.GetPosition();
    OnUpdatePositionValues(evt);
}

void MyPanel::OnLeftIsDown(wxMouseEvent& evt)
{
    auto delta = this->mousepos - evt.GetPosition();
    this->mousepos = evt.GetPosition();
    this->pan[0] -= (delta.x/this->zoom);
    this->pan[1] -= (delta.y/this->zoom);
    Refresh();
}

// 691
// Change the window/level when the right mouse button is dragged.
void MyPanel::OnRightIsDown(wxMouseEvent& evt)
{
    auto delta = this->mousepos - evt.GetPosition();
    this->mousepos = evt.GetPosition();
    Refresh();
}

void MyPanel::OnUpdatePositionValues(wxMouseEvent& evt)
{
    wxPoint pos;

    if (evt.GetEventType() == wxEVT_NULL)//(evt == None) // called from OnMouseEnter() or OnMouseLeave()
        pos = /*np.array*/(this->mousepos);
    else
        pos = /*np.array*/(evt.GetPosition());

    // On the Mac, the cursor position is shifted by 1 pixel to the left
    if (wxPlatformIs(wxOS_MAC))
        pos.x = pos.x - 1;//pos = pos - 1;

    // Determine the coordinates with respect to the current zoom and pan
    int w,h;
    this->GetClientSize(&w, &h);
    int xpos = (int)(pos.x/this->zoom - this->pan[0] - (w - this->bwidth*this->zoom) /
               (2*this->zoom));
    int ypos = (int)(pos.y/this->zoom - this->pan[1] - (h - this->bheight*this->zoom) /
               (2*this->zoom));

    // Save the coordinates so they can be used by plugins
    this->xpos = xpos;
    this->ypos = ypos;
}
