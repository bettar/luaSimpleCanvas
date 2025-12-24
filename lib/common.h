// Alex Bettarini - 24 Mar 2025

#pragma once
#include <string>

namespace HPGL
{

class engineBase
{
public:
    virtual void initialize(float x1, float y1, float x2, float y2) {};
    virtual void initialize(bool yUp = true) {};
    virtual void terminate() = 0;
    
    virtual void setLineDashed(bool dashed = true) = 0;
    virtual void anyLine(float startX, float startY, float dx, float dy) = 0;
    virtual void anyRect(float x1, float y1, float x2, float y2) = 0;

    void horLine(float startX, float startY, float w);
    void verLine(float startX, float startY, float h);
    
    virtual void horBracket(float startX, float startY, float endX) {}

    virtual void textSize(float sz) {}
    virtual void labelRelative(float dx, float dy, const std::string & label) {}
    virtual void labelAt(float x, float y, const std::string & label) {}

    virtual void noteAt(float x, float y) {}
    
    virtual void whitePen(float thickness) {}
    virtual void grayPen(float thickness) {}
    virtual void blackPen(float thickness) {}
    virtual void redPen(float thickness) {}
    virtual void greenPen(float thickness) {}
    virtual void bluePen(float thickness) {}
    virtual void cyanPen(float thickness) {}
    virtual void magentaPen(float thickness) {}
    virtual void yellowPen(float thickness) {}
};

}
