// Alex Bettarini - 2025
#include "minor.h"

static
const std::vector<struct oneNote> Amin_mel_up = {
	{1, 2,"1", true},
	{1, 4,"3"},
	{1, 5,"4"},
	{2, 0,"0"},
	{2, 2,"1", false, true},
	{2, 4,"2", false, true},
	{2, 6,"4"},
	{3, 0,"0", true},
	{3, 2,"1"},
	{3, 3,"2"},
	{3, 5,"4"},
	{3, 7,"1", false, true},
	{3, 9,"2", false, true},
	{3, 11,"4"},
	{3, 12,"3h", true}
};

static
const std::vector<struct oneNote> Amin_mel_down = {
	{1, 2,"1", true},
	{1, 4,"3"},
	{1, 5,"4"},
	{2, 0,"0"},
	{2, 2,"1"},
	{2, 3,"2"},
	{2, 5,"4"},
	{3, 0,"0", true},
	{3, 2,"1"},
	{3, 3,"2"},
	{3, 5,"4"},
	{3, 7,"1"},
	{3, 8,"2"},
	{3, 10,"4"},
	{3, 12,"3h", true}
};

static
const std::vector<struct oneNote> Amin_harm = {
	{1, 2,"1", true},
	{1, 4,"3"},
	{1, 5,"4"},
	{2, 0,"0"},
	{2, 2,"1"},
	{2, 3,"2", false, true},
	{2, 6,"4"},
	{3, 0,"0", true},
	{3, 2,"1"},
	{3, 3,"2"},
	{3, 5,"4"},
	{3, 7,"1"},
	{3, 8,"2", false, true},
	{3, 11,"4"},
	{3, 12,"3h", true}
};

// vol1 p34
static
const std::vector<struct oneNote> Amin_chord = {
	{1, 2,"1", true},
	{1, 5,"4"},
	{2, 2,"1"},
	{3, 0,"0", true},
	{3, 3,"1", false, true},
	{3, 7,"4"},
	{3, 12,"3h", true}
};

static
const std::vector<struct oneNote> Emin_mel_up = {
	{0, 4,"2", true},
	{0, 6,"4"},
	{1, 0,"0"},
	{1, 2,"1", false, true},
	{1, 4,"2", false, true},
	{1, 6,"4"},
	{2, 1,"1"},
	{2, 2,"2", true},
	{2, 4,"4"},
	{2, 5,"1", false, true},
	{2, 7,"2", false, true},
	{2, 9,"4"},
	{3, 4,"1"},
	{3, 6,"3"},
	{3, 7,"1", true},
	{3, 9,"3"},
	{3, 10,"4"}
};

static
const std::vector<struct oneNote> Emin_mel_down = {
	{0, 4,"2", true},
	{0, 6,"4"},
	{1, 0,"0"},
	{1, 2,"1"},
	{1, 4,"3"},
	{1, 5,"4"},
	{2, 0,"0"},
	{2, 2,"1", true},
	{2, 4,"3"},
	{2, 5,"4"},
	{3, 0,"0"},
	{3, 2,"1"},
	{3, 3,"2"},
	{3, 5,"4"},
	{3, 7,"1", true}
};

static
const std::vector<struct oneNote> Emin_harm = {
	{0, 4,"2", true},
	{0, 6,"4"},
	{1, 0,"0"},
	{1, 2,"1"},
	{1, 4,"3"},
	{1, 5,"4"},
	{2, 1,"1"},
	{2, 2,"1", true},
	{2, 4,"3"},
	{2, 5,"4"},
	{3, 0,"0"},
	{3, 2,"1"},
	{3, 3,"2"},
	{3, 6,"?"},
	{3, 7,"1", true}
};

// vol1 p34
static
const std::vector<struct oneNote> Emin_chord = {
	{0, 4,"3", true},
	{1, 0,"0"},
	{1, 4,"3"},
	{2, 2,"1", true},
	{2, 5,"1", false, true},
	{2, 9,"4"},
	{3, 7,"2", true}
};

// Dotzauer vol 1, p36
// Dotzauer vol 2, p34
static
const std::vector<struct oneNote> Bmin_mel_up = {
	{0, 2,"1", false, true},
	{0, 4,"2", false, true},
	{0, 6,"4"},
	{1, 1,"1"},
	{1, 3,"1"},
	{1, 4,"2", true},
	{1, 6,"4"},
	{2, 0,"0"},
	{2, 2,"1", false, true},
	{2, 4,"2", false, true},
	{2, 6,"4"},
	{3, 1,"1", false},
	{3, 2,"2", true},
	{3, 4,"4"},
	{3, 5,"1", false, true},
	{3, 7,"2", false, true},
	{3, 9,"4"}
};

static
const std::vector<struct oneNote> Bmin_mel_down = {
	{0, 2,"1", false, true},
	{0, 4,"2", false, true},
	{0, 6,"4"},
	{1, 0,"0"},
	{1, 2,"1", false, true},
	{1, 4,"2", true, true},
	{1, 6,"4"},
	{2, 0,"0"},
	{2, 2,"1"},
	{2, 4,"3"},
	{2, 5,"4"},
	{3, 0,"0"},
	{3, 2,"1", true},
	{3, 4,"3"},
	{3, 5,"1", false, true},
	{3, 7,"2", false, true},
	{3, 9,"4"}
};

static
const std::vector<struct oneNote> Bmin_harm = {
	{0, 2,"1", false, true},
	{0, 4,"2", false, true},
	{0, 6,"4"},
	{1, 0,"0"},
	{1, 3,"1"},
	{1, 4,"2", true},
	{1, 6,"4"},
	{2, 0,"0"},
	{2, 2,"1"},
	{2, 4,"3"},
	{2, 5,"4"},
	{3, 1,"1"},
	{3, 2,"2", true},
	{3, 4,"4"},
	{3, 5,"1", false, true},
	{3, 7,"2", false, true},
	{3, 9,"4"}
};

// Dotzauer vol 2, p34
static
const std::vector<struct oneNote> Bmin_chord = {
	{1, 4,"3", true},
	{2, 0,"0"},
	{2, 4,"3"},
	{3, 2,"1", true},
	{3, 5,"1", false, true},
	{3, 9,"4"}
};

// vol2 p40
static
const std::vector<struct oneNote> Fsmin_mel_up = {
	{0, 6,"1", true},
	{0, 8,"3"},
	{0, 9,"4"},
	{1, 4,"1", false, true},
	{1, 6,"2", false, true},
	{1, 8,"4"},
	{2, 3,"1"},
	{2, 4,"2", true},
	{2, 6,"4"},
	{3, 0,"0"},
	{3, 2,"1"},
	{3, 4,"2"},
	{3, 6,"1"},
	{3, 8,"3"},
	{3, 9,"4", true}
};

static
const std::vector<struct oneNote> Fsmin_mel_down = {
	{0, 6,"1", true},
	{0, 8,"3"},
	{0, 9,"4"},
	{1, 4,"1"},
	{1, 6,"3"},
	{1, 7,"4"},
	{2, 2,"1", false, true},
	{2, 4,"2", true, true},
	{2, 6,"4"},
	{3, 0,"0"},
	{3, 2,"1", false, true},
	{3, 4,"2"},
	{3, 5,"1", false, true},
	{3, 7,"2", false, true},
	{3, 9,"4", true}
};

static
const std::vector<struct oneNote> Fsmin_harm = {
};

static
const std::vector<struct oneNote> Fsmin_chord = {
	{0, 6,"4", true},
	{1, 2,"1", false, true},
	{1, 6,"4"},
	{2, 4,"2", true},
	{2, 7,"1", false, true},
	{2, 11,"4"},
	{3, 9,"2", true},
};

// vol2, p42
static
const std::vector<struct oneNote> Csmin_mel_up = {
	{0, 1,"1", true},
	{0, 3,"3"},
	{0, 4,"4"},
	{0, 6,"1", false, true},
	{0, 8,"2", false, true},
	{0, 10,"4"},
	{1, 5,"1"},
	{1, 6,"2", true},
	{1, 8,"4"},
	{2, 2,"1", false, true},
	{2, 4,"2", false, true},
	{2, 6,"4"},
	{3, 1,"1"},
	{3, 3,"3"},
	{3, 4,"1", true},
	{3, 6,"3"},
	{3, 7,"1", false, true},
	{3, 9,"2", false, true},
	{3, 11,"4"}
};

static
const std::vector<struct oneNote> Csmin_mel_down = {
	{0, 1,"1", true},
	{0, 3,"3"},
	{0, 4,"4"},
	{0, 6,"1"},
	{0, 8,"3"},
	{0, 9,"4"},
	{1, 4,"1", false, true},
	{1, 6,"2", true, true},
	{1, 8,"4"},
	{2, 2,"1", false, true},
	{2, 4,"2", false, true},
	{2, 6,"4"},
	{3, 0,"0"},
	{3, 2,"1", false, true},
	{3, 4,"2", true, true},
	{3, 6,"4"},
	{3, 7,"1", false, true},
	{3, 9,"2", false, true},
	{3, 11,"4"}
};

static
const std::vector<struct oneNote> Csmin_harm = {
};

static
const std::vector<struct oneNote> Csmin_chord = {
	{0, 1,"1", true},
	{0, 4,"4"},
	{1, 1,"1"},
	{1, 6,"4", true},
	{2, 2,"1", false, true},
	{2, 6,"4"},
	{3, 4,"2", true},
	{3, 7,"1", false, true},
	{3, 11,"4"}
};

// Vol 2, p 42
static
const std::vector<struct oneNote> Gsmin_mel_up = {
	{1, 1,"1", true},
	{1, 3,"3"},
	{1, 4,"4"},
	{1, 6,"1", false, true},
	{1, 8,"2", false, true},
	{1, 10,"4"},
	{2, 5,"1"},
	{2, 6,"2", true},
	{2, 8,"4"},
	{3, 2,"1", false, true},
	{3, 4,"2", false, true},
	{3, 6,"4"},
	{3, 8,"1"},
	{3, 10,"3"},
	{3, 11,"4", true}
};

static
const std::vector<struct oneNote> Gsmin_mel_down = {
	{0, 1,"1"}, // IV
	{0, 3,"1"},
	{0, 4,"2"},
	{0, 6,"4"},
	{1, 1,"1", true},
	{1, 3,"3"},
	{1, 4,"4"},
	{1, 6,"1"},
	{1, 8,"3"},
	{1, 9,"4"},
	{2, 4,"1", false, true},
	{2, 6,"2", true, true},
	{2, 8,"4"},
	{3, 2,"1", false, true},
	{3, 4,"2", false, true},
	{3, 6,"4"},
	{3, 7,"1", false, true},
	{3, 9,"2", false, true},
	{3, 11,"4", true}
};

static
const std::vector<struct oneNote> Gsmin_harm = {
};

static
const std::vector<struct oneNote> Gsmin_chord = {
	{1, 1,"1", true},
	{1, 4,"4"},
	{2, 1,"1"},
	{2, 6,"1", true},
	{2, 9,"4"},
	{3, 6,"1"},
	{3, 11,"4", true}
};

// Vol 2, p45
static
const std::vector<struct oneNote> Ebmin_mel_up = {
	{0, 3,"1", true},
	{0, 5,"3"},
	{0, 6,"4"},
	{1, 1,"1", false, true},
	{1, 3,"2", false, true},
	{1, 5,"4"},
	{1, 7,"1"},
	{1, 8,"2", true},
	{1, 10,"4"},
	{2, 4,"1", false, true},
	{2, 6,"2", false, true},
	{2, 8,"4"},
	{3, 3,"1"},
	{3, 5,"3"},
	{3, 6,"4", true}
};

static
const std::vector<struct oneNote> Ebmin_mel_down = {
	{0, 3,"1", true},
	{0, 5,"3"},
	{0, 6,"4"},
	{1, 1,"1"},
	{1, 3,"3"},
	{1, 4,"4"},
	{1, 6,"1", false, true},
	{1, 8,"2", true, true},
	{1, 10,"4"},
	{2, 4,"1", false, true},
	{2, 6,"2", false, true},
	{2, 8,"4"},
	{3, 2,"1", false, true},
	{3, 4,"2", false, true},
	{3, 6,"4", true}
};

static
const std::vector<struct oneNote> Ebmin_harm = {
};

static
const std::vector<struct oneNote> Ebmin_chord = {
	{0, 3,"1", true, true},
	{0, 7,"4"},
	{1, 3,"1"},
	{1, 8,"4", true},
	{2, 4,"1", false, true},
	{2, 8,"4"},
	{3, 6,"2", true}
};

// Vol 2, p46
static
const std::vector<struct oneNote> Bbmin_mel_up = {
	{1, 3,"1", true},
	{1, 5,"3"},
	{1, 6,"4"},
	{2, 1,"1", false, true},
	{2, 3,"2", false, true},
	{2, 5,"4"},
	{2, 7,"1"},
	{2, 8,"2", true},
	{2, 10,"4"},
	{3, 4,"1", false, true},
	{3, 6,"2", false, true},
	{3, 8,"4"},
	{3, 10,"1"},
	{3, 12,"3"}, // mistake in Dotzauer ?
	{3, 13,"4", true}
};

static
const std::vector<struct oneNote> Bbmin_mel_down = {
	{1, 3,"1", true},
	{1, 5,"3"},
	{1, 6,"4"},
	{2, 1,"1"},
	{2, 3,"3"},
	{2, 4,"4"},
	{2, 6,"1", false, true},
	{2, 8,"2", true, true},
	{2, 10,"4"},
	{3, 4,"1", false, true},
	{3, 6,"2", false, true},
	{3, 8,"4"},
	{3, 9,"1", false, true},
	{3, 11,"2", false, true},
	{3, 13,"4", true}
};

static
const std::vector<struct oneNote> Bbmin_harm = {
};

static
const std::vector<struct oneNote> Bbmin_chord = {
	{1, 3,"1", true},
	{1, 6,"4"},
	{2, 3,"1"},
	{2, 8,"1", true},
	{2, 11,"4"},
	{3, 8,"1"},

	{3, 13,"4", true}
};

// Vol 2, p 43
static
const std::vector<struct oneNote> Fmin_mel_up = {
	{0, 5,"1", true},
	{0, 7,"3"},
	{0, 8,"4"},
	{1, 3,"1", false, true},
	{1, 5,"2", false, true},
	{1, 7,"4"},
	{2, 2,"1"},
	{2, 3,"2", true},
	{2, 5,"4"},
	{2, 6,"1", false, true},
	{2, 8,"2", false, true},
	{2, 10,"4"},
	{3, 5,"1"},
	{3, 7,"3"},
	{3, 8,"4", true}
};

static
const std::vector<struct oneNote> Fmin_mel_down = {
	{0, 5,"1", true},
	{0, 7,"3"},
	{0, 8,"4"},
	{1, 3,"1"},
	{1, 5,"3"},
	{1, 6,"4"},
	{2, 1,"1", false, true},
	{2, 3,"2", true, true},
	{2, 5,"4"},
	{2, 6,"1", false, true},
	{2, 8,"2", false, true},
	{2, 10,"4"},
	{3, 4,"1", false, true},
	{3, 6,"2", false, true},
	{3, 8,"4", true}
};

static
const std::vector<struct oneNote> Fmin_harm = {
};

static
const std::vector<struct oneNote> Fmin_chord = {
	{0, 5,"4", true},
	{1, 1,"1", false, true},
	{1, 5,"4"},
	{2, 3,"2", true},
	{2, 6,"1", false, true},
	{2, 10,"4"},
	{3, 8,"2", true}
};

// Vol 2, p29
static
const std::vector<struct oneNote> Cmin_mel_up = {
	{0, 0,"0", true},
	{0, 2,"1"},
	{0, 3,"2"},
	{0, 5,"4"},
	{1, 0,"0"},
	{1, 2,"1"},
	{1, 4,"2"},
	{1, 5,"1", true},
	{2, 0,"0"},
	{2, 1,"1", false, true},
	{2, 3,"2", false, true},
	{2, 5,"4"},
	{3, 0,"0"},
	{3, 2,"1"},
	{3, 3,"2", true},
	{3, 5,"4"},
	{3, 6,"1", false, true},
	{3, 8,"2", false, true},
	{3, 10,"4"}
};

static
const std::vector<struct oneNote> Cmin_mel_down = {
	{0, 0,"0", true},
	{0, 2,"1"},
	{0, 3,"2"},
	{0, 5,"4"},
	{1, 0,"0"},
	{1, 1,"1", false, true},
	{1, 3,"2"},
	{1, 5,"1", true},
	{1, 7,"3"},
	{1, 8,"4"},
	{2, 3,"1"},
	{2, 5,"3"},
	{2, 6,"4"},
	{3, 1,"1", false, true},
	{3, 3,"2", true, true},
	{3, 5,"4"},
	{3, 6,"1", false, true},
	{3, 8,"2", false, true},
	{3, 10,"4"}
};

static
const std::vector<struct oneNote> Cmin_harm = {
	{0, 0,"0", true},
	{0, 2,"1"},
	{0, 3,"2"},
	{0, 5,"4"},
	{1, 0,"0"},
	{1, 1,"?"},
	{1, 4,"?"},
	{1, 5,"?", true},
	{2, 0,"0"},
	{2, 1,"1"},
	{2, 3,"1"},
	{2, 5,"3"},
	{2, 6,"4"},
	{3, 2,"1"},
	{3, 3,"2", true},
	{3, 5,"4"},
	{3, 6,"1", false, true},
	{3, 8,"2", false, true},
	{3, 10,"4"}
};

static
const std::vector<struct oneNote> Cmin_chord = {
	{0, 0,"0", true},
	{0, 3,"2"},
	{1, 0,"0"},
	{1, 5,"4", true},
	{2, 1,"1", false, true},
	{2, 5,"4"},
	{3, 3,"2", true},
	{3, 6,"1", false, true},
	{3, 10,"4"}
};

// Vol 2, p6
static
const std::vector<struct oneNote> Gmin_mel_up = {
	{1, 0,"0", true},
	{1, 2,"1"},
	{1, 3,"2"},
	{1, 5,"4"},
	{2, 0,"0"},
	{2, 2,"1"},
	{2, 4,"3"},
	{2, 5,"4", true},
	{3, 0,"0"},
	{3, 1,"1", false, true},
	{3, 3,"2", false, true},
	{3, 5,"4"},
	{3, 7,"1"},
	{3, 9,"3"},
	{3, 10,"4", true}
};

static
const std::vector<struct oneNote> Gmin_mel_down = {
	{0, 0,"0"}, // IV
	{0, 2,"1"},
	{0, 3,"2"},
	{0, 5,"4"},
	{1, 0,"0", true},
	{1, 2,"1"},
	{1, 3,"2"},
	{1, 5,"4"},
	{2, 0,"0"},
	{2, 1,"1", false, true},
	{2, 3,"2", false, true},
	{2, 5,"4", true},
	{3, 0,"0"},
	{3, 1,"1", false, true},
	{3, 3,"2", false, true},
	{3, 5,"4"},
	{3, 6,"1", false, true},
	{3, 8,"2", false, true},
	{3, 10,"4", true}
};

static
const std::vector<struct oneNote> Gmin_harm = {
	{1, 0,"0", true},
	{1, 2,"1"},
	{1, 3,"2"},
	{1, 5,"4"},
	{2, 0,"0"},
	{2, 1,"1"},
	{2, 4,"3"},
	{2, 5,"4", true},
	{3, 0,"0"},
	{3, 1,"1", false, true},
	{3, 3,"2", false, true},
	{3, 5,"4"},
	{3, 6,"1"},
	{3, 9,"3"},
	{3, 10,"4", true}
};

static
const std::vector<struct oneNote> Gmin_chord = {
	{0, 2,"?"}, // V
	{1, 0,"0", true},
	{1, 3,"?"},
	{2, 0,"0"},
	{2, 5,"4", true},
	{3, 1,"1", false, true},
	{3, 5,"4"},
	{3, 10,"4", true}
};

// vol2, p6
static
const std::vector<struct oneNote> Dmin_mel_up = {
	{0, 2,"1", true},
	{0, 4,"3"},
	{0, 5,"4"},
	{1, 0,"0"},
	{1, 2,"1", false, true},
	{1, 4,"2", false, true},
	{1, 6,"4"},
	{2, 0,"0", true},
	{2, 2,"1"},
	{2, 3,"2"},
	{2, 5,"4"},
	{3, 0,"0"},
	{3, 2,"1"},
	{3, 4,"3"},
	{3, 5,"4", true},
	{3, 7,"1"},
	{3, 8,"2"},
	{3, 10,"4"},
	{3, 12,"3h"}
};

static
const std::vector<struct oneNote> Dmin_mel_down = {
	{0, 2,"1", true},
	{0, 4,"3"},
	{0, 5,"4"},
	{1, 0,"0"},
	{1, 2,"1"},
	{1, 3,"2"},
	{1, 5,"4"},
	{2, 0,"0", true},
	{2, 2,"1"},
	{2, 3,"2"},
	{2, 5,"4"},
	{3, 0,"0"},
	{3, 1,"1", false, true},
	{3, 3,"2", false, true},
	{3, 5,"4", true},
	{3, 7,"1"},
	{3, 8,"2"},
	{3, 10,"4"},
	{3, 12,"3h"}
};

static
const std::vector<struct oneNote> Dmin_harm = {
	{0, 2,"1", true},
	{0, 4,"3"},
	{0, 5,"4"},
	{1, 0,"0"},
	{1, 2,"1"},
	{1, 3,"2"},
	{1, 6,"4"},
	{2, 0,"0", true},
	{2, 2,"1"},
	{2, 3,"2"},
	{2, 5,"4"},
	{3, 0,"0"},
	{3, 1,"1"},
	{3, 4,"3"},
	{3, 5,"4", true},
	{3, 7,"1"},
	{3, 8,"2"},
	{3, 10,"4"},
	{3, 12,"3h"}
};

static
const std::vector<struct oneNote> Dmin_chord = {
};

const std::vector<std::vector<struct oneNote>> allScales = {
    Amin_mel_up,  Amin_mel_down,  Amin_harm,  Amin_chord,
    Emin_mel_up,  Emin_mel_down,  Emin_harm,  Emin_chord, // 1#
    Bmin_mel_up,  Bmin_mel_down,  Bmin_harm,  Bmin_chord, // 2#
    Fsmin_mel_up, Fsmin_mel_down, Fsmin_harm, Fsmin_chord, // 3#
    Csmin_mel_up, Csmin_mel_down, Csmin_harm, Csmin_chord, // 4#
    Gsmin_mel_up, Gsmin_mel_down, Gsmin_harm, Gsmin_chord, // 5#
    Ebmin_mel_up, Ebmin_mel_down, Ebmin_harm, Ebmin_chord, // 6# 6b
    Bbmin_mel_up, Bbmin_mel_down, Bbmin_harm, Bbmin_chord, // 5b
    Fmin_mel_up,  Fmin_mel_down,  Fmin_harm,  Fmin_chord, // 4b
	Cmin_mel_up,  Cmin_mel_down,  Cmin_harm,  Cmin_chord, // 3b
	Gmin_mel_up,  Gmin_mel_down,  Gmin_harm,  Gmin_chord, // 2b
	Dmin_mel_up,  Dmin_mel_down,  Dmin_harm,  Dmin_chord, // 1b
};

//{"Dmaj", u8"2♯♭"},
const std::vector<struct scaleInfo> keyInfo = {
	{"A min", "", {13, 13, 13, 13}}, 
	{"E min", "1#", {11, 8, 8, 10}}, 
	{"B min", "2#", {10, 10, 10, 10}}, 
	{"F# min", "3#", {10, 10, 8, 12}}, 
	{"C# min", "4#", {12, 12, 8, 12}},
	{"G# min", "5# / 7b", {12, 12, 8, 12}}, 
	{"Eb min", "6b", {11, 11, 8, 9}},
	{"Bb min", "5b", {14, 14, 8, 14}},
	{"F min", "4b", {11, 11, 8, 11}}, 
	{"C min", "3b", {11, 11, 11, 11}}, 
	{"G min", "2b", {11, 11, 11, 11}}, 
	{"D min", "1b", {13, 13, 13, 8}}, 
};
