// Alex Bettarini - 24 Mar 2025

#include <iostream>
#include <string>
#include <vector>

#include "major.h"
#include "maj_arp.h"

#include "engineHgl.h" // for hpglReadability

#define FIRST_STRING_X	20 	// left

#ifdef STAND_ALONE // using HGL renderer
#define FIRST_STRING_Y	170 // top
#else
#define FIRST_STRING_Y  40 // top
#endif

#define NUM_STRINGS		4 	// strings on diagram, not strings on instrument
#define DELTA_STRINGS	10
#define DELTA_FRETS		10

static struct {
	float left;
	float top;
} fb; // fretboard

static int _numFrets = 8;

struct optionsMaj opt;

// to position the fretboard
float getX_fromStringNum(int n)
{
	return (fb.left + n*DELTA_STRINGS);
}

// fret 0 is open string
float getY_fromFretNum(int n)
{
#ifdef STAND_ALONE // using HGL renderer
	return fb.top - n*DELTA_FRETS; // invert Y coordinate
#else
    return fb.top + n*DELTA_FRETS; // invert Y coordinate
#endif
}

static
void note_string_fret_label(HPGL::engineBase& engine,
                            int str, int fret, const std::string & label)
{
	float x = getX_fromStringNum(str);
	float y = getY_fromFretNum(fret);
    engine.noteAt(x, y);
#ifdef STAND_ALONE
    engine.labelRelative(1.5, 1.5, label);
#else
    engine.labelRelative(1.5, -1.5, label);
#endif
}

// At fb.left, fb.top
void drawPattern(int idx, std::string legend, HPGL::engineBase& engine)
{
	std::cout << "LO5;"; // label align center-middle

	auto pattern = allScales[idx];
	for (int i=0; i<pattern.size(); i++) {
		float x = getX_fromStringNum(pattern[i].str);
		float y = getY_fromFretNum(pattern[i].fret);

		if (pattern[i].stretch) {
			//float x2 = getX_fromStringNum(pattern[i+1].str);
			float y2 = getY_fromFretNum(pattern[i+1].fret);
            engine.redPen(0.5);
            engine.verLine(x, y, y2-y);
		}

#if 0 // FIXME: online converter makes black areas
		// Clear the note background
		{
            engine.whitePen(1.0);
			std::cout << "PU;PA" << x-2 << "," << y-3 << ";RR4,6;";
		}
#endif

        engine.blackPen(0.3);
        engine.labelAt(x, y, pattern[i].label);
        if (pattern[i].root)
            engine.anyRect(x-3, y-4, 6, 7);
	}
	
	std::cout << "LO1;"; // label align bottom-left

#ifdef STAND_ALONE
    auto yy = getY_fromFretNum(0) + 10;
#else
    auto yy = getY_fromFretNum(0) - 10;
#endif
    engine.labelAt(fb.left, yy, legend);
}

void drawPositionFrets(float atX, HPGL::engineBase& engine)
{
	float width = (NUM_STRINGS-1)*DELTA_STRINGS;

    engine.grayPen(0.3);
	for (int i=0; i<_numFrets; i++) {
		float y = getY_fromFretNum(i);
        engine.horLine(atX, y, width);
	}
	
    engine.blackPen(0.6);

	std::vector<int> markedFrets = {0,2,4,5,7,12};
	for (auto fret : markedFrets) {
		if (fret <= (_numFrets-1))
            engine.horLine(atX, getY_fromFretNum(fret), width);
	} 
}

void drawStrings(float atX, float atY, HPGL::engineBase& engine)
{
    engine.grayPen(0.2);
	float height = (_numFrets-1)*DELTA_FRETS;
#ifdef STAND_ALONE
    height = -height;
#endif
	for (int i=0; i<NUM_STRINGS; i++) {
		float x = (atX+i*DELTA_STRINGS);
        engine.verLine(x, atY, height);
	}

	//std::cout << "LT;"; // restore continuous
    HPGL::engineHgpl::hpglReadability();
}

void drawScaleArpeggio(int scaleNum, HPGL::engineBase& engine)
{
	// scale
	_numFrets = keyInfo[scaleNum/2].nFretsScale;
	drawStrings(fb.left, fb.top, engine);
	drawPositionFrets(fb.left, engine);
	drawPattern(scaleNum, keyInfo[scaleNum/2].name + " scale", engine);
	
	// arpeggio
	fb.left += 6*DELTA_STRINGS;
	_numFrets = keyInfo[scaleNum/2].nFretsArp;
	drawStrings(fb.left, fb.top, engine);
	drawPositionFrets(fb.left, engine);
	drawPattern(scaleNum+1, keyInfo[scaleNum/2].name + " arpeggio", engine);

	if (!keyInfo[scaleNum/2].alterations.empty())
	{
#ifdef STAND_ALONE
        engine.greenPen(0.5);
        auto yy = getY_fromFretNum(0) + 15;
#else
        engine.greenPen(1);
        auto yy = getY_fromFretNum(0) - 15;
#endif
        engine.labelAt( fb.left - 2*DELTA_STRINGS, yy,
                       keyInfo[scaleNum/2].alterations);
	}
}

int do_major_stuff(int idxLeft, int idxRight,
                   HPGL::engineBase& engine)
{
    int w = 280;
    int h = 210;
    float m = 5;
    engine.initialize(0,0,w,h);
    
    std::cout << "SI0.18,0.36;";// Absolute Character Size    width,height
    std::cout << "FT0;";        // Fill type: solid colour
    HPGL::engineHgpl::hpglReadability();

    // frame
    engine.blackPen(1.0);
    engine.setLineDashed();
    engine.anyRect(m, m, w-2*m, h-2*m); // XYWH
    engine.setLineDashed(false);

    fb.top = FIRST_STRING_Y;

    // Pagination: left side
    //if (opt.keyList.size() > 0)
    {
        fb.left = FIRST_STRING_X;
        drawScaleArpeggio(idxLeft, engine);
    }

    // Pagination: right side
    //if (opt.keyList.size() > 1)
    {
        fb.left = FIRST_STRING_X + 14*DELTA_STRINGS;
        drawScaleArpeggio(idxRight, engine);
    }

    engine.terminate();
}

int major_stuff(int argc, char** argv, HPGL::engineBase& engine)
{
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
				// 1 -> 0
				// 2 -> 2
				// 3 -> 4
				keyIdx = std::stoi(argv[ii]);
				keyIdx--;
				keyIdx *= 2; // each key has 'scale' and 'arpeggio'
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

    if (opt.keyList.size() > 1) {
        do_major_stuff(opt.keyList.at(0),
                       opt.keyList.at(1),
                       engine);
    }

    return EXIT_SUCCESS;
}
