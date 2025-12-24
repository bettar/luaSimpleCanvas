// Alex Bettarini - 24 Mar 2025

#include <iostream>

#include "common.h"

namespace HPGL
{

void engineBase::horLine(float startX, float startY, float endX)
{
    anyLine(startX, startY, endX, 0);
}

void engineBase::verLine(float startX, float startY, float h)
{
    anyLine(startX, startY, 0, h);
}

} // namespace
