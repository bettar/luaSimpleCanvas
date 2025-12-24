// Alex Bettarini - 2025
#pragma once
#include "common.h"
#include <vector>

struct optionsMaj {
    int scalesPerPage;
    int numPages;
    bool verbose = false;
    std::vector<int> keyList;
};

int do_major_stuff(int idxLeft, int idxRight, HPGL::engineBase& engine);

int major_stuff(int argc, char** argv, HPGL::engineBase& eng);
