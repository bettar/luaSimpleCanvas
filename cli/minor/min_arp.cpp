// Alex Bettarini - 24 Mar 2025

#include <iostream>
#include <string>
#include <vector>

#include "engineHgl.h"
#include "minor.h"
#include "min_arp.h"

#define FIRST_STRING_X	20 	// left
#define FIRST_STRING_Y	170 // top
#define NUM_STRINGS		4 	// strings on diagram, not strings on instrument
#define DELTA_STRINGS	10
#define DELTA_FRETS		10

extern struct optionsMin opt;
//HPGL::engineHgpl engine;

static struct {
	float left;
	float top;
} fb; // fretboard

static int _numFrets = 8;

// to position the fretboard
float getX_fromStringNum(int n)
{
	return (fb.left + n*DELTA_STRINGS);
}

// fret 0 is open string
float getY_fromFretNum(int n)
{
	return fb.top - n*DELTA_FRETS; // invert Y coordinate
}

static
void note_string_fret_label(HPGL::engineBase& engine,
                            int str, int fret, const std::string & label)
{
	float x = getX_fromStringNum(str);
	float y = getY_fromFretNum(fret);
    engine.noteAt(x, y);
    engine.labelRelative(1.5, 1.5, label);
}

// At fretboard.left, fretboard.top
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

		// Clear the note background
		{
            engine.whitePen(1.0);
			std::cout << "PU;PA" << x-2 << "," << y-3 << ";RR4,6;";
		}

        engine.blackPen(0.3);
		std::cout << "PU;PA" << x << "," << y << ";LB" << pattern[i].label << "*;";
		if (pattern[i].root)
			std::cout << "PU;PA" << x-3 << "," << y-4 << ";ER6,7;"; // rectangle
	}
	
	std::cout << "LO1;"; // label align bottom-left

	auto yy = getY_fromFretNum(0) + 12;
	std::cout << "PU;PA" << fb.left << "," << yy << ";LB" << legend << "*;";
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
	for (int i=0; i<NUM_STRINGS; i++) {
		float x = (atX+i*DELTA_STRINGS);
        engine.verLine(x, atY, -height);
	}

    HPGL::engineHgpl::hpglReadability();
}

#define KEY_INFO keyInfo[scaleNum/opt.scalesPerKey]

void drawAllPatternsForAKey(int scaleNum, HPGL::engineBase& engine)
{
	const std::vector<std::string> legend = {"melodic up","melodic down\n\r=natural (=aeolian)", "harmonic", "arpeggio"};

	for (int i=0;i<4;i++)
	{
		_numFrets = KEY_INFO.nFretsScale[i];
		drawStrings(fb.left, fb.top, engine);
		drawPositionFrets(fb.left, engine);
		drawPattern(scaleNum+i, legend[i], engine);

		fb.left += 6*DELTA_STRINGS;
	}	

    engine.blackPen(1.0);
	auto xx = 120;
	auto yy = getY_fromFretNum(0) + 20;
    engine.labelAt(xx, yy, KEY_INFO.name);
	//std::cout << "PU;PA" << xx << "," << yy << ";LB" << KEY_INFO.name <<"*;";

	if (!KEY_INFO.alterations.empty())
	{
        engine.greenPen(0.5);
        engine.labelAt(xx+20, yy,KEY_INFO.alterations);
		//std::cout << "PU;PA" << xx+20 << "," << yy << ";LB" << KEY_INFO.alterations << "*;";
	}
}

void minor_stuff(HPGL::engineBase& engine)
{
    engine.initialize();//0,0,400,300);
    
    std::cout << "SI0.18,0.36;";// Absolute Character Size    width,height
    std::cout << "FT0;";        // Fill type: solid colour
    HPGL::engineHgpl::hpglReadability();

    // frame
    engine.blackPen(1.0);
    int frameW = 250;
    int frameH = 200;
    engine.setLineDashed();
    engine.anyRect(0, 0, frameW, frameH);
    engine.setLineDashed(false);

    fb.top = FIRST_STRING_Y;

    // Pagination: left side
    if (opt.keyList.size() > 0)
    {
        fb.left = FIRST_STRING_X;
        drawAllPatternsForAKey(opt.keyList.at(0), engine);
    }

#if 0
    // Pagination: right side
    if (opt.keyList.size() > 1)
    {
        fb.left = FIRST_STRING_X + 14*DELTA_STRINGS;
        drawAllPatternsForAKey(opt.keyList.at(1));
    }
#endif
    engine.terminate();
}
