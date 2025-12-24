// Alex Bettarini - 2025
#pragma once
#include "common.h"
#include <vector>

struct optionsMin {
    int numPages;
    int scalesPerKey = 4;  // each key has 2x melodic, harmonic, arpeggio
    bool verbose = false;
    std::vector<int> keyList;
};

void minor_stuff(HPGL::engineBase& engine);
