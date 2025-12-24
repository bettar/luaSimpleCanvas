// Alex Bettarini - 2025
#include <iostream>

#include "engineHgl.h"

namespace HPGL
{


//void engineHgpl::initialize(float x1, float y1, // 0% point
//                            float x2, float y2) // 100% point
void engineHgpl::initialize(bool yUp)
{
    // Initialize
    std::cout << "IN;";
    
    // /////////////////////////////////////////////////////////////////////////
    // (p2x-p1x)/(xmax-xmin) = kx   --->  kx/40  [mm/unit] along X
    // (p2y-p1y)/(ymax-ymin) = ky   --->  ky/40  [mm/unit] along Y

    // Plotter coordinates
    // Input
    // IP p1x,p1y,p2x,p2y;
    // XY unit of minimum plotter movement is 0.025mm
    //      1unit/0.025mm = 40 units/mm
    if (yUp) {
        std::cout << "IP0,0,4000,4000;";
    }
    else {
        std::cout << "IP0,0,4000,-4000;";
    }

    // User coordinates
    // Scale
    // SC xmin,xmax,ymin,ymax;
    std::cout << "SC0,100,0,100;";  // user coordinates same as mm
    
    // /////////////////////////////////////////////////////////////////////////
    std::cout << "DS2;";            // Designate Charset
    std::cout << "SI0.12,0.24;";    // Absolute Character Size    width,height
    std::cout << "SS;";             // Select Standard Charset
    std::cout << "DT*,1;";          // Define Label Terminator
    
    engineHgpl::hpglReadability();
}

void engineHgpl::terminate()
{
    // TODO: sort by pen usage (hint: use string streams)
}

void engineHgpl::hpglReadability()
{
#ifndef NDEBUG
    std::cout << std::endl;
#endif
}

void engineHgpl::horBracket(float startX, float startY, float endX)
{
    const int dy = 3;
    std::cout << "PU;";
    std::cout << "PA" << startX << "," << (startY+dy) << ";";

    std::cout << "PD;";
    std::cout << "PA" << startX << "," << startY << ";";
    std::cout << "PR" << endX << "," << 0 << ";";
    std::cout << "PR" << 0 << "," << dy << ";";
    
    // reset position
    std::cout << "PU;";
    std::cout << "PA" << startX << "," << startY << ";";
}

void engineHgpl::anyLine(float startX, float startY, float endX, float endY)
{
    std::cout << "PU;PA" << startX << "," << startY << ";";

    std::cout << "PD;PR" << endX << "," << endY << ";";
    //std::cout << "PU;";
}

// "LT3;" dashed
// "LT1;" dotted
void engineHgpl::setLineDashed(bool dashed)
{
    if (dashed)
        std::cout << "LT3;";    // Long dotted line
    else
        std::cout << "LT;";     // Line type
}

// dashed rectangle
void engineHgpl::anyRect(float x, float y, float dx, float dy)
{
    std::cout << "PU;PA"
    << (int)x << ","
    << (int)y << ";";
    
    std::cout << "ER" // Edge rectangle relative
    << (int)dx << ","
    << (int)dy << ";";
}

void engineHgpl::labelRelative(float dx, float dy, const std::string & label)
{
    std::cout << "PU;PR" << dx << "," << dy << ";LB" << label << "*;";
}

void engineHgpl::labelAt(float x, float y, const std::string & label)
{
    std::cout << "PU;PA" << x << "," << y << ";LB" << label << "*;";
}

void engineHgpl::noteAt(float x, float y)
{
#if 1
    // FIXME: Imagemagick says "Warning: Zero line segment length -- skipped"
    std::cout << "PU;PA" << x << "," << y << ";CI1.5;"; // circle
#else
    std::cout << "PU;PA" << x-1 << "," << y-1 << ";ER2,2;"; // rectangle
#endif
}

void engineHgpl::grayPen(float thickness)
{
    //std::cout << "SP4,0.5,0.5,0.1;PW" << thickness << ",1;";
    std::cout << "SP1,0.5,0.5,0.1;PW" << thickness << ",1;";
}

void engineHgpl::whitePen(float thickness)
{
    std::cout << "SP0;PW" << thickness << ",1;";
}

void engineHgpl::blackPen(float thickness)
{
    std::cout << "SP1;PW" << thickness << ",1;";
}

void engineHgpl::redPen(float thickness)
{
    std::cout << "SP2;PW" << thickness << ",2;";
}

void engineHgpl::greenPen(float thickness)
{
    std::cout << "SP3;PW" << thickness << ",3;";
}

void engineHgpl::bluePen(float thickness)
{
    std::cout << "SP4;PW" << thickness << ",3;";
}

void engineHgpl::cyanPen(float thickness)
{
    std::cout << "SP5;PW" << thickness << ",3;";
}

void engineHgpl::magentaPen(float thickness)
{
    std::cout << "SP6;PW" << thickness << ",3;";
}

void engineHgpl::yellowPen(float thickness)
{
    std::cout << "SP7;PW" << thickness << ",3;";
}

}
