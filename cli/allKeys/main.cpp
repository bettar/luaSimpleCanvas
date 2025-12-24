// Alex Bettarini - 24 Mar 2025

#include <iostream>

#include "wx/wx.h"

#include "engineHgl.h"
#include "engineWx.h"

#include "diag1.h"

int main(int argc, char** argv)
{
    std::cerr << argv[0] << std::endl;
 
    
    if (true) {
        HPGL::engineHgpl engine;
        doDiag1(engine, false);//false means Y pointing down and (0,0) at TL
    }
#if 0
    else {
        wxImage::AddHandler(new wxPNGHandler);
        
        wxMemoryDC memDC;
        HPGL::engineWx engine(&memDC);
        doDiag1b(engine);
        
        engine._bmp.SaveFile("diag1-123.png", wxBITMAP_TYPE_PNG);
    }
#endif
}
