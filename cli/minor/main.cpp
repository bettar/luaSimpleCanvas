// Alex Bettarini - 2025
#include <iostream>
#include <string>
#include <vector>

#include "minor.h"
#include "min_arp.h"
#include "engineHgl.h"

struct optionsMin opt;
//extern struct optionsMin opt;

int main(int argc, char** argv)
{
    std::cerr << argv[0] << std::endl;

    if (argc < 2) {
        std::cerr << "Must specify pattern number" << std::endl;
        return EXIT_FAILURE;
    }

    int keyIdx=0;
    int ii = 1;
    while (ii < argc)
    {
#ifndef NDEBUG
        std::cerr << "argv[" << ii << "]=" << argv[ii] << "\n";
#endif
        std::string sarg(argv[ii]);
        if (sarg == "-v")
        {
            opt.verbose = true;
            std::cerr << "\t\tBuilt " << __DATE__ << " with"
    #ifdef __GNUC__
            << " GNU g++" << __VERSION__
    #endif
            << " compiler version " << __cplusplus
            << std::endl;
        }
        else
        {
            try {
                keyIdx = std::stoi(argv[ii]);
                keyIdx--;
                keyIdx *= opt.scalesPerKey;
#ifndef NDEBUG
                std::cerr << __LINE__ << ", keyIdx:" << keyIdx << std::endl;
#endif
                if (keyIdx < allScales.size())
                    opt.keyList.push_back(keyIdx);
            }
            catch (const std::invalid_argument& e) {
                std::cerr << "Invalid argument" << e.what() << std::endl;
                return EXIT_FAILURE;
            }
        }

        ii++;
    } // while

    HPGL::engineHgpl engine;
    minor_stuff(engine);
    
    return EXIT_SUCCESS;
}
