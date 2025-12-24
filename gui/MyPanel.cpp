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
        gc->DrawBitmap(tempBmp,
                       margin, margin,
                       size.GetWidth()-2*margin,
                       size.GetHeight()-2*margin);
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
