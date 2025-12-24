// Alex Bettarini - 2025
#pragma once
#include "common.h"

namespace HPGL
{

class engineHgpl : public engineBase
{
public:
    static void hpglReadability();
    
    void initialize(bool yUp = true) override;
    //void initialize(float x1, float y1, float x2, float y2) override;
    void terminate() override;
    
    void setLineDashed(bool dashed = true) override;
    void anyLine(float startX, float startY, float dx, float dy) override;
    void anyRect(float x1, float y1, float x2, float y2) override;

    void horBracket(float startX, float startY, float endX) override;

    void labelRelative(float dx, float dy, const std::string & label) override;
    void labelAt(float x, float y, const std::string & label) override;
    
    void noteAt(float x, float y) override;
    
    void whitePen(float thickness) override;
    void grayPen(float thickness) override;
    void blackPen(float thickness) override;
    void redPen(float thickness) override;
    void greenPen(float thickness) override;
    void bluePen(float thickness) override;
    void cyanPen(float thickness) override;
    void magentaPen(float thickness) override;
    void yellowPen(float thickness) override;
};

}
