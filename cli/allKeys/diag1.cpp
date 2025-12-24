// Alex Bettarini - 2025
#include <iostream>
#include <string>
#include <vector>

#include "diag1.h"
#include "engineHgl.h" // for hpglReadability

#define FIRST_STRING_X      45 // left
#define FIRST_STRING_Y      90 // bottom
#define NUM_STRINGS         21 // strings on diagram, not string on instrument
#define DELTA_STRINGS       10

#define NUM_FRETS           15
#define DELTA_FRETS         DELTA_STRINGS // square geometry
#define FIRST_FRET_Y        FIRST_STRING_Y

#define NUM_SEMITONES_IN_OCTAVE     12    // microtonality has > 12
#define STRINGS_TUNED_BY            5    // fifths for cell0

static bool _yUp;

// to position the fretboard
static
float getX_fromStringNum(int n)
{
    return (FIRST_STRING_X+n*DELTA_STRINGS);
}

// fret 0 is open string
static
float getY_fromFretNum(int n)
{
    if (_yUp)
        return FIRST_FRET_Y + (NUM_FRETS-n-1)*DELTA_FRETS; // invert Y coordinate

    return (FIRST_FRET_Y + n*DELTA_FRETS);
}

static
void note_string_fret_label(HPGL::engineBase& engine,
                            int str, int fret, const std::string & label)
{
    float x = getX_fromStringNum(str);
    float y = getY_fromFretNum(fret);
    engine.noteAt(x, y);
	if (_yUp)
	    engine.labelRelative(1.5, 1.5, label);
	else
	    engine.labelRelative(1.5, -1.5, label);
}

struct scale {
    int semitones;
    std::string label;
};

const std::vector<struct scale> majScale = {
{2,"Root"},
{2,"II"},
{1,"III"},
{2,"IV"},
{2,"V"},
{2,"VI"},
{1,"VII"}};

const std::vector<struct scale> minScale = {
{2,"Root"},
{1,"II"},
{2,"IIIm"},
{2,"IV"},
{2,"V"},
{1,"VI"},
{2,"VIIm"}};

const std::vector<struct scale> pentaMinScale = {
{3,"Root"},
{2,"IIIm"},
{2,"IV"},
{3,"V"},
{2,"VIIm"}};

const std::vector<struct scale> pentaMajScale = {
{2,"Root"},
{2,"II"},
{3,"III"},
{2,"V"},
{3,"VI"}};

const std::vector<struct scale> diminishedScale = {
{3,"Root"},
{3,"IIIm"},
{3,"Vb"},
{3,"VI"}};

void drawScaleOnString( HPGL::engineBase& engine,
                        int sn,
                        const std::vector<struct scale> sc,
                        int offsetSemitones=0) // fret for root
{
    auto nn = sc.size();
        
    // Ensure 'fret' is a positive number falling within the first octave
    int fret = (offsetSemitones + NUM_SEMITONES_IN_OCTAVE) % NUM_SEMITONES_IN_OCTAVE;

#if 0 //def VERBOSE
    std::cerr << "\t\t\tLine " << __LINE__
        << ", string #" << sn
        //<< ", nn:" << nn
        << ", offsetSemitones:" << offsetSemitones
        << ", root at fret:" << fret
        << std::endl;
#endif
    for (int i=0; i<nn; i++) // for each note in the scale
    {
        //std::cerr << "Line " << __LINE__ << ", note:" << i << ", " << sc[i].label << std::endl;
            
        if (i==0) engine.blackPen(0.6); // before drawing root note
        
        note_string_fret_label(engine, sn, fret, sc[i].label);
        if (fret+NUM_SEMITONES_IN_OCTAVE < NUM_FRETS)
            note_string_fret_label(engine, sn, fret+NUM_SEMITONES_IN_OCTAVE, sc[i].label); // alias note in another octave

        if (i==0) engine.redPen(0.6); // after drawing root note
        
        fret += sc[i].semitones;
        fret %= NUM_SEMITONES_IN_OCTAVE;
    }
    
    HPGL::engineHgpl::hpglReadability();
}

void drawStrings(HPGL::engineBase& engine)
{
    engine.blackPen(0.2);
    float height = (NUM_FRETS-1)*DELTA_FRETS;
    for (int i=0; i<NUM_STRINGS; i++) {
        float x = (FIRST_STRING_X+i*DELTA_STRINGS);
        engine.verLine(x, FIRST_STRING_Y, height);
    }

    HPGL::engineHgpl::hpglReadability();
}

struct annotation {
    int deltaX;
    int deltaY;
    std::string label;
    std::string flatsSharps;
};

static
void drawKeysFlatsSharps(HPGL::engineBase& engine)
{
    const std::vector<struct annotation> legendKeys = {
    {1, 1,"C#","7#"},
    {1, 1,"F#","6#"},
    {1, 1,"B", "5#"},
    {1, 1,"E", "4#"},
    {1, 1,"A", "3#"},
    {1, 1,"D", "2#"},
    {1, 2,"G", "1#"},
    {1,-1,"C", ""},
    {1,-2,"F", "1b"},
    {1,-1,"Bb","2b"},
    {1,-1,"Eb","3b"},
    {1,-3,"Ab","4b"},
    {1, 1,"Db","5b"},
    {1, 1,"Gb","6b"},
    {1, 1,"Cb","7b"},
    {1, 1,"E", ""},
    {1, 1,"A", ""}
    };

//    blackPen(0.3);
//    horLine(getX_fromStringNum(0), getY_fromFretNum(NUM_FRETS+1), (NUM_STRINGS-1)*DELTA_STRINGS); // capotasto

    const int numCelloStrings = 4;
    float width = (numCelloStrings-1)*DELTA_STRINGS;

    int stepY = 0;
    const int deltaStep = 5;
    auto n = legendKeys.size();
    
    // Calculate vertical size of keys diagram
    // to be used as displacement between the two diagrams
    int keysHeight = 0;
    {
        int uy = 3; // start with a margin
        for (int i=0; i<n; i++) {
            uy += legendKeys[i].deltaY;
        }
        keysHeight = uy*deltaStep;
    }
        
    for (int i=0; i<n; i++) {
        float x = getX_fromStringNum(i);
        float y;
        if (_yUp) {
            y = FIRST_STRING_Y - 52 + stepY*deltaStep;
        }
        else {
            y = getY_fromFretNum(NUM_FRETS) + stepY*deltaStep;
            y += keysHeight; // fixup spacing between frets and keys
        }
        engine.blackPen(0.3);
        //horLine(x, y, width);
        engine.horBracket(x, y, width);
        engine.labelRelative(15, 1.5, legendKeys[i].label);

        engine.greenPen(0.3);
        engine.labelRelative(-15, 0, legendKeys[i].flatsSharps);

        if (_yUp)
            stepY += legendKeys[i].deltaY;
        else
            stepY -= legendKeys[i].deltaY;
    }
    /*
    for (int i=0; i<6; i++) {
        float x = getX_fromStringNum(10+i);
        float y = FIRST_STRING_Y - (8 + i*5);
        horLine(x, y, width);
    }*/
    
    HPGL::engineHgpl::hpglReadability();
}

static
void drawFretsAtString(HPGL::engineBase& engine, int sn)
{
    const int numCelloStrings = 4;
    float x = getX_fromStringNum(sn);
    float width = (numCelloStrings-1)*DELTA_STRINGS;
    
    engine.blackPen(0.3);
    for (int i=0; i<NUM_FRETS; i++) {
        float y = getY_fromFretNum(i);
        engine.horLine(x, y, width);
    }

    HPGL::engineHgpl::hpglReadability();

    // Positions
    engine.blackPen(1.2);
    engine.horLine(x, getY_fromFretNum(2), width); // first
    engine.horLine(x, getY_fromFretNum(4), width); // second
    engine.horLine(x, getY_fromFretNum(5), width); // third
    engine.horLine(x, getY_fromFretNum(7), width); // fourth
    
    HPGL::engineHgpl::hpglReadability();
}

void doDiag1(HPGL::engineBase& engine, bool yUp)
{
    _yUp = yUp;
    
    //std::cout << "IN;IP;SC0,100,0,100,1;"; // Initialize;Input;Scale
    engine.initialize(yUp);

    // frame
    engine.blackPen(1.0);
    engine.setLineDashed();
    engine.anyRect(10, 10, 280, 280); // XYWH
    engine.setLineDashed(false);
#ifndef NDEBUG
    float x1=0, y1=0, x2=300, y2=300;
    const float m = 20.; // margin
    engine.greenPen(4.0);
    engine.anyLine(m, m, -m+(x2-x1)-m, -m+(y2-y1)-m);

    engine.redPen(2.0);
    engine.anyLine(m, y2-m, -m+(x2-m), -(y2-m)+m);

    engine.bluePen(1.0);
    const float ptx = 15.;
    const float pty = 15.;
    engine.blackPen(1.0);
    engine.anyLine(ptx,pty+20, 20,-20);
    engine.anyLine(ptx,pty,    20,20);
    engine.labelRelative(0, 0, "hello 15,15");
    engine.noteAt(ptx, pty);
    
//    engine.terminate();
//    return;
#endif
    drawStrings(engine);

    engine.blackPen(0.3);
    engine.horLine(getX_fromStringNum(0), getY_fromFretNum(0), (NUM_STRINGS-1)*DELTA_STRINGS); // capotasto
    engine.horLine(getX_fromStringNum(0), getY_fromFretNum(7), (NUM_STRINGS-1)*DELTA_STRINGS); // 1st string shift
    if (14 >= (NUM_FRETS-1))
        engine.horLine(getX_fromStringNum(0), getY_fromFretNum(14), (NUM_STRINGS-1)*DELTA_STRINGS); // 2nd string shift

    const int snRootFret0 = 7;
    drawFretsAtString(engine, snRootFret0);
    //drawFretsAtString(8);

#if 0
    // note
    redPen(0.6);
    float fretboardX = getX_fromStringNum(3);
    noteAt(fretboardX, getY_fromFretNum(0)); // first fret
    labelRelative(0, 2.5, "Red");
    labelRelative(0, 1.0, "III");
    
    // root note
    blackPen(0.5);
    noteAt(fretboardX, getY_fromFretNum(9));
    labelRelative(0.5, 1.5, "Root");
    labelRelative(0, 1.0, "V");
#endif

    //drawScaleOnString(0, minScale);
    //drawScaleOnString(1, pentaMinScale);

#if 1
    for (int i=0; i<NUM_SEMITONES_IN_OCTAVE; i++)
    {
        #if 1
        int fifths = (i*STRINGS_TUNED_BY) % NUM_SEMITONES_IN_OCTAVE;
        #else
        int fifths = i;
        #endif
        
        int sn = (i+snRootFret0) % NUM_SEMITONES_IN_OCTAVE;
        //std::cerr << "Line " << __LINE__ << ", i:" << i << ", sn:" << sn << std::endl;
        drawScaleOnString(engine, sn, majScale, fifths);
        if (sn+NUM_SEMITONES_IN_OCTAVE < NUM_STRINGS)
            drawScaleOnString(engine, sn+NUM_SEMITONES_IN_OCTAVE, majScale, fifths); // alias string
    }
#else
    drawScaleOnString(engine, 0, majScale, -3);
    drawScaleOnString(engine, 1, majScale, -2);
    drawScaleOnString(engine, 2, majScale, -1);
    drawScaleOnString(engine, 3, majScale);
    //drawScaleOnString(4, majScale, 1);
    //drawScaleOnString(5, majScale, 2);
    //drawScaleOnString(6, majScale, 3);
    //drawScaleOnString(7, majScale, 4);
    //drawScaleOnString(8, majScale, 5);
#endif

    drawKeysFlatsSharps(engine);
    engine.terminate();
}
