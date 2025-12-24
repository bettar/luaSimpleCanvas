// Alex Bettarini - 2025
#include <iostream>
#include "maj_arp.h"
#include "engineHgl.h"

int main(int argc, char** argv)
{
    std::cerr << argv[0] << std::endl;

    if (argc < 2) {
        std::cerr << "Must specify pattern number" << std::endl;
        return EXIT_FAILURE;
    }
    
    HPGL::engineHgpl engine;
    major_stuff( argc, argv, engine);
}
