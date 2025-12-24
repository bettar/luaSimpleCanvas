// Alex Bettarini - 17 Dec 2025
#include <iostream>

#include <wx/wx.h>
#include "wx/log.h"

#include "engineWx.h"

namespace HPGL
{

#define SCALING_FACTOR_f    2.9 // empyrical

engineWx::engineWx(wxMemoryDC* dc)
: _memDC(dc)
{
    
}

void engineWx::initialize(float x1, float y1, float x2, float y2)
{
    //wxLogMessage("%s:%d %s (%.1f,%.1f) (%.1f,%.1f)", __FILE_NAME__, __LINE__, __FUNCTION__, x1,y1,x2,y2);
    
    _width = x2-x1;
    _height = y2-y1;
#ifndef NDEBUG
    auto k = _memDC->GetPPI(); //wxSize(72,72)
    auto k2 = _memDC->GetResolution(); // -1
    auto k3 = _memDC->GetDepth();  // 32
    auto k4 = _memDC->GetContentScaleFactor(); // 1
    wxSize sz1(_width, _height);
    auto sz2 = _memDC->FromDIP(sz1);
    auto sz3 = _memDC->ToDIP(sz1);
    auto mm = _memDC->GetMapMode();
#endif
    if (_memDC->GetMapMode() == wxMM_METRIC)
        _bmp = wxBitmap(_width*SCALING_FACTOR_f, _height*SCALING_FACTOR_f, -1);
    else
        _bmp = wxBitmap(_width, _height, -1);
    
    //tempBmp.UseAlpha(); // Enable transparency
    
    _memDC->SelectObject(_bmp);
    
    //_memDC->SetUserScale(1.0,-1.0); // failed attempt to reverse Y axis direction

#ifdef NDEBUG
    _memDC->SetBackground(*wxWHITE_BRUSH);
    _memDC->Clear();
    // For filled areas
    _memDC->SetBrush(wxBrush(wxColour(0,0,0,wxALPHA_TRANSPARENT)));
#else
    _memDC->SetBackground(*wxYELLOW_BRUSH);
    _memDC->Clear();

    // For filled areas
    _memDC->SetBrush(wxBrush(wxColour(0,255,0,40)));
#endif

    wxFont font(10, wxFONTFAMILY_ROMAN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
    _memDC->SetFont(font);
    
#ifndef NDEBUG
    const float m = 20.; // margin
    greenPen(4.0);
    anyLine(m, m, _width - 2*m, _height - 2*m);

    redPen(2.0);
    anyLine(m, y2-m, -m+(x2-m), -(y2-m)+m);

    bluePen(1.0);
    const float ptx = 15.;
    const float pty = 15.;
    blackPen(1.0);
    anyLine(ptx,pty+20, 20,-20);
    anyLine(ptx,pty,    20,20);
    labelRelative(0, 0, "hello 15,15");
    noteAt(ptx, pty);
#endif
}

void engineWx::textSize(float sz)
{
    _memDC->SetFont(wxFontInfo(sz));
}

void engineWx::terminate()
{
    _memDC->SelectObject(wxNullBitmap);
    // now the caller can use _bmp
}

void engineWx::horBracket(float startX, float startY, float endX)
{
    const int dy = 6;
    anyLine(startX, startY, 0, dy);
    anyLine(startX, startY+dy, endX, 0);
    anyLine(startX+endX, startY+dy, 0, -dy);
    
    // reset position
    savedX = startX;
    savedY = startY;
}

void engineWx::anyLine(float startX, float startY, float dx, float dy)
{
    //wxLogMessage("%s:%d %s, from:(%.1f,%.1f) delta:(%.1f,%.1f)", __FILE_NAME__, __LINE__, __FUNCTION__, startX,startY, dx,dy);
    
    wxPoint ptFrom(startX, startY);
    wxPoint ptTo(startX+dx, startY+dy);
    _memDC->DrawLine(ptFrom, ptTo);
    savedX = startX;
    savedY = startY;
}

void engineWx::setLineDashed(bool dashed)
{
    auto currentPen = _memDC->GetPen();

    if (dashed)
        currentPen.SetStyle(wxPENSTYLE_SHORT_DASH);
    else
        currentPen.SetStyle(wxPENSTYLE_SOLID);

    _memDC->SetPen(currentPen);
}

// dashed rectangle
void engineWx::anyRect(float x1, float y1, float w, float h)
{
    _memDC->DrawRectangle(x1, y1, w, h); // XYWH
}

void engineWx::labelRelative(float dx, float dy, const std::string & label)
{
    //wxLogMessage("%s:%d %s, %s)", __FILE_NAME__, __LINE__, __FUNCTION__, label);
    //_memDC->DrawText(wxString( label.c_str(), wxConvUTF8), savedX+dx, savedY+dy);
    labelAt(savedX+dx, savedY+dy, label);
}

void engineWx::labelAt(float x, float y, const std::string & label)
{
    _memDC->DrawText(wxString( label.c_str(), wxConvUTF8), x, y);
}

void engineWx::noteAt(float x, float y)
{
    _memDC->DrawCircle(x, y, 3);
    
    savedX = x;
    savedY = y;
}

void engineWx::whitePen(float thickness)
{
    _memDC->SetPen(wxPen(wxColour(255,255,255), thickness));
    //_memDC->SetPen(*wxWHITE_PEN);
    _memDC->SetTextForeground(_memDC->GetPen().GetColour());
}

void engineWx::grayPen(float thickness)
{
    _memDC->SetPen(wxPen(wxColour(128,128,128), thickness));
    //_memDC->SetPen(*wxGREY_PEN);
    _memDC->SetTextForeground(_memDC->GetPen().GetColour());
}

void engineWx::blackPen(float thickness)
{
    _memDC->SetPen(wxPen(wxColour(0,0,0), thickness));
    //_memDC->SetPen(*wxBLACK_PEN);
    _memDC->SetTextForeground(*wxBLACK);
}

void engineWx::redPen(float thickness)
{
    _memDC->SetPen(wxPen(wxColour(255,0,0), thickness));
    //_memDC->SetPen(*wxRED_PEN);
    _memDC->SetTextForeground(*wxRED);
}

void engineWx::greenPen(float thickness)
{
    _memDC->SetPen(wxPen(wxColour(0,255,0), thickness));
    //_memDC->SetPen(*wxGREEN_PEN);
    _memDC->SetTextForeground(*wxGREEN);
}

void engineWx::bluePen(float thickness)
{
    _memDC->SetPen(wxPen(wxColour(0,0,255), thickness));
    //_memDC->SetPen(*wxBLUE_PEN);
    _memDC->SetTextForeground(*wxBLUE);
}

void engineWx::cyanPen(float thickness)
{
    _memDC->SetPen(wxPen(wxColour(0,255,255), thickness));
    //_memDC->SetPen(*wxCYAN_PEN);
    _memDC->SetTextForeground(*wxCYAN);
}

void engineWx::magentaPen(float thickness)
{
    _memDC->SetPen(wxPen(wxColour(255,0,255), thickness));
    //_memDC->SetTextForeground(*wxMAGENTA);
    _memDC->SetTextForeground(_memDC->GetPen().GetColour());
}

void engineWx::yellowPen(float thickness)
{
    _memDC->SetPen(wxPen(wxColour(255,255,0), thickness));
    //_memDC->SetPen(*wxYELLOW_PEN);
    _memDC->SetTextForeground(*wxYELLOW);
}

}
