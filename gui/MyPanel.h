// Alex Bettarini - 16 Dec 2025
#pragma once

#include "wx/wx.h"
#include "wx/dcgraph.h"

#include "MyFrameBase.h"

typedef enum {
    DRAW_NOTHING,
    DRAW_STRING_DIAGRAM,
    DRAW_MAJOR_SCALE,
    DRAW_MINOR_SCALE
} drawItem;

class MyPanel : public MyPanelBase
{
    wxGraphicsRenderer* m_renderer;
    bool m_useAntiAliasing = true;
    wxBitmap DrawContents(const wxSize size);
    double zoom = 1.0;
    int xpos, ypos;
    int pan[2];
    // Image Size
    int bheight = 1;
    int bwidth = 1;
    bool exportRequest = false;
    
protected:
    void OnPaint( wxPaintEvent& event );

public:
    MyPanel( wxWindow* parent );

    void OnExport();
    void OnZoomIn();
    void OnZoomOut();
    void OnPanUp();
    void OnPanDown();
    void OnPanLeft();
    void OnPanRigth();
    drawItem whatToDraw = DRAW_NOTHING;
};
