// Alex Bettarini - 2025
#include "major.h"

static
const std::vector<struct oneNote> Cmaj_scale = {
	{0, 0,"0", true},
	{0, 2,"1"},
	{0, 4,"3"},
	{0, 5,"4"},
	{1, 0,"0"},
	{1, 2,"1"},
	{1, 4,"3"},
	{1, 5,"4", true},
	{2, 0,"0"},
	{2, 2,"1"},
	{2, 3,"2"},
	{2, 5,"4"},
	{3, 0,"0"},
	{3, 2,"1"},
	{3, 3,"2", true}
};

static
const std::vector<struct oneNote> Cmaj_arp = {
	{0, 0,"0", true},
	{0, 4,"3"},
	{1, 0,"0"},
	{1, 5,"4", true},
	{2, 2,"1"},
	{2, 5,"4"},
	{3, 3,"2", true}
};

static
const std::vector<struct oneNote> Gmaj_scale = {
	{1, 0,"0", true},
	{1, 2,"1"},
	{1, 4,"3"},
	{1, 5,"4"},
	{2, 0,"0"},
	{2, 2,"1"},
	{2, 4,"3"},
	{2, 5,"4", true},
	{3, 0,"0"},
	{3, 2,"1"},
	{3, 3,"2"},
	{3, 5,"4"},
	{3, 7,"1"},
	{3, 9,"3"},
	{3, 10,"4", true}
};

static
const std::vector<struct oneNote> Gmaj_arp = {
	{0, 7, "4", true},
	{1, 0, "0", true},
	{1, 4, "1"},
	{1, 7, "4"},
	{2, 5, "2", true},
	{2, 9, "1"},
	{2, 12,"3"},
	{3, 10,"2", true}
};

static
const std::vector<struct oneNote> Dmaj_scale = {
	{0, 2,"1", true, true},
	{0, 4,"2", false, true},
	{0, 6,"4"},
	{1, 0,"0"},
	{1, 2,"1", false, true},
	{1, 4,"2", false, true},
	{1, 6,"4"},
	{2, 0,"0", true},
	{2, 2,"1"},
	{2, 4,"3"},
	{2, 5,"4"},
	{3, 0,"0"},
	{3, 2,"1"},
	{3, 4,"3"},
	{3, 5,"4", true}
};

static
const std::vector<struct oneNote> Dmaj_arp = {
	{0, 2,"1", true, true},
	{0, 6,"4"},
	{1, 2,"1"},
	{2, 0,"0", true},
	{2, 4,"3"},
	{3, 0,"0"},
	{3, 5,"4", true}
};

static
const std::vector<struct oneNote> A_maj_scale = {
	{1, 2,"1", true, true},
	{1, 4,"2", false, true},
	{1, 6,"4"},
	{2, 0,"0"},
	{2, 2,"1", false, true},
	{2, 4,"2", false, true},
	{2, 6,"4"},
	{3, 0,"0", true},
	{3, 2,"1"},
	{3, 4,"3"},
	{3, 5,"1"},
	{3, 7,"3"},
	{3, 9,"1",false,true},
	{3, 11,"2"},
	{3, 12,"3", true}
};

static
const std::vector<struct oneNote> A_maj_arp = {
	{0, 9, " ", true},
	{1, 2, "1", true},
	{1, 6, "1"},
	{1, 9, "4"},
	{2, 7, "2", true},
	{2, 11, "1"},
	{2, 14,"3"},
	{3, 12,"2", true}
};

static
const std::vector<struct oneNote> E_maj_scale = {
	{0, 4,"1", true, true},
	{0, 6,"2", false, true},
	{0, 8,"4"},
	{1, 2,"1", false, true},
	{1, 4,"2", false, true},
	{1, 6,"4"},
	{2, 1,"1"},
	{2, 2,"2", true},
	{2, 4,"4"},
	{2, 6,"1"},
	{2, 7,"2"},
	{2, 9,"4"},
	{3, 4,"1"},
	{3, 6,"3"},
	{3, 7,"4", true}
};

static
const std::vector<struct oneNote> E_maj_arp = {
	{0, 4, "4", true},
	{1, 1, "1"},
	{1, 4, "4"},
	{2, 2, "2", true},
	{2, 6, "1"},
	{2, 9, "4"},
	{3, 7, "2", true}
};

static
const std::vector<struct oneNote> B_maj_scale = {
	{1, 4,"2", true},
	{1, 6,"4"},
	{2, 1,"1"},
	{2, 2,"2"},
	{2, 4,"4"},
	{2, 6,"1"},
	{2, 8,"3"},
	{2, 9,"4", true},
	{3, 4,"1"},
	{3, 6,"3"},
	{3, 7,"1"},
	{3, 9,"3"},
	{3, 11,"1", false, true},
	{3, 13,"2"},
	{3, 14,"3", true}
};

static
const std::vector<struct oneNote> B_maj_arp = {
	{1, 4, "2", true},
	{1, 8, "1"},
	{1, 11, "4"},
	{2, 9, "2", true},
	{2, 13, "1"},
	{2, 16, "3"},
	{3, 14, "2", true}
};

static
const std::vector<struct oneNote> Fs_maj_scale = {
	{0, 6,"2", true},
	{0, 8,"4"},
	{1, 3,"1"},
	{1, 4,"2"},
	{1, 6,"4"},
	{2, 1,"1"},
	{2, 3,"3"},
	{2, 4,"4", true},
	{2, 6,"1"},
	{2, 8,"3"},
	{3, 2,"1"},
	{3, 4,"3"},
	{3, 6,"1"},
	{3, 8,"3"},
	{3, 9,"4", true}
};

static
const std::vector<struct oneNote> Fs_maj_arp = {
	{0, 6, "2", true},
	{1, 3, "1"},
	{1, 6, "4"},
	{2, 4, "2", true},
	{2, 8, "1"},
	{2, 11, "4"},
	{3, 9, "2", true}
};

static
const std::vector<struct oneNote> Db_maj_scale = {
	{0, 1,"1", true},
	{0, 3,"3"},
	{0, 5,"1"},
	{0, 6,"2"},
	{0, 8,"4"},
	{1, 3,"1"},
	{1, 5,"3"},
	{1, 6,"4", true},
	{2, 1,"1"},
	{2, 3,"3"},
	{2, 4,"2"},
	{2, 6,"4"},
	{3, 1,"1"},
	{3, 3,"3"},
	{3, 4,"4", true}
};

static
const std::vector<struct oneNote> Db_maj_arp = {
	{0, 1, "1", true},
	{0, 5, "1"},
	{0, 8, "4"},
	{1, 6, "2", true},
	{2, 3, "1"},
	{2, 6, "4"},
	{3, 4, "2", true}
};

static
const std::vector<struct oneNote> Ab_maj_scale = {
	{1, 1,"1", true},
	{1, 3,"3"},
	{1, 5,"1"},
	{1, 6,"2"},
	{1, 8,"4"},
	{2, 3,"1"},
	{2, 5,"3"},
	{2, 6,"4", true},
	{3, 1,"1"},
	{3, 3,"3"},
	{3, 4,"2"},
	{3, 6,"4"},
	{3, 8,"1"},
	{3, 10,"3"},
	{3, 11,"4", true}
};

static
const std::vector<struct oneNote> Ab_maj_arp = {
	{1, 1, "1", true},
	{1, 5, "1"},
	{1, 8, "4"},
	{2, 6, "2", true},
	{2, 10, "1"},
	{2, 13, "3"},
	{3, 11, "2", true}
};

static
const std::vector<struct oneNote> Eb_maj_scale = {
	{0, 3,"2", true},
	{0, 5,"4"},
	{1, 0,"0"},
	{1, 1,"1", false, true},
	{1, 3,"2", false, true},
	{1, 5,"4"},
	{2, 0,"0"},
	{2, 1,"1", true, true},
	{2, 3,"2"},
	{2, 5,"1"},
	{2, 6,"2"},
	{2, 8,"4"},
	{3, 3,"1"},
	{3, 5,"3"},
	{3, 6,"4", true}
};

static
const std::vector<struct oneNote> Eb_maj_arp = {
	{0, 3, "2", true},
	{1, 0, "0"},
	{1, 3, "2"},
	{2, 1, "1", true},
	{2, 5, "1"},
	{2, 8, "4"},
	{3, 6, "2", true}
};

static
const std::vector<struct oneNote> Bb_maj_scale = {
	{1, 3,"2", true},
	{1, 6,"4"},
	{2, 0,"0"},
	{2, 1,"1", false, true},
	{2, 3,"2", false, true},
	{2, 5,"4"},
	{3, 0,"0"},
	{3, 1,"1", true, true},
	{3, 3,"2"},
	{3, 5,"1"},
	{3, 6,"2"},
	{3, 8,"4"},
	{3, 10,"1", false, true},
	{3, 12,"2"},
	{3, 13,"3", true}
};

static
const std::vector<struct oneNote> Bb_maj_arp = {
	{1, 3, "2", true},
	{1, 7, "1"},
	{1, 10, "4"},
	{2, 8, "2", true},
	{2, 12, "1"},
	{2, 15, "4"},
	{3, 13, "2", true}
};

static
const std::vector<struct oneNote> F_maj_scale = {
	{0, 5,"4", true},
	{1, 0,"0"},
	{1, 2,"1"},
	{1, 3,"2"},
	{1, 5,"4"},
	{2, 0,"0"},
	{2, 2,"1"},
	{2, 3,"2", true},
	{2, 5,"4"},
	{3, 0,"0"},
	{3, 1,"1", false, true},
	{3, 3,"2"},
	{3, 5,"1"},
	{3, 7,"3"},
	{3, 8,"4", true}
};

static
const std::vector<struct oneNote> F_maj_arp = {
	{0, 5,"4", true},
	{1, 2,"1"},
	{1, 5,"4"},
	{1, 10,"4", true},
	{2, 3,"2", true},
	{2, 7,"1"},
	{2, 10,"4"},
	{3, 8,"2", true}
};

const std::vector<std::vector<struct oneNote>> allScales = {
	Cmaj_scale, Cmaj_arp,
	Gmaj_scale, Gmaj_arp, // 1#
	Dmaj_scale, Dmaj_arp, // 2#
	A_maj_scale, A_maj_arp, // 3#
	E_maj_scale, E_maj_arp, // 4#
	B_maj_scale, B_maj_arp, // 5# 7b
	Fs_maj_scale, Fs_maj_arp, // 6# 6b
	Db_maj_scale, Db_maj_arp,  // 5b
	Ab_maj_scale, Ab_maj_arp,  // 4b
	Eb_maj_scale, Eb_maj_arp,  // 3b
	Bb_maj_scale, Bb_maj_arp,  // 2b
	F_maj_scale, F_maj_arp  // 1b
};

//{"Dmaj", u8"2♯♭"},
const std::vector<struct scaleInfo> keyInfo = {
	{"C maj", ""},
	{"G maj", "1♯", 11, 13},
	{"D maj", "2♯"},
	{"A maj", "3♯", 13, 15},
	{"E maj", "4♯", 10, 10},
	{"B maj", "5♯\n\r7♭", 15, 17},
	{"F# maj", "6♯\n\r6♭", 10, 12},
	{"Db maj", "7♯\n\r5♭", 9, 9},
	{"Ab maj", "4♭", 12, 14},
	{"Eb maj", "3♭", 9, 9},
	{"Bb maj", "2♭", 14, 16},
	{"F maj", "1♭", 9, 11}};
