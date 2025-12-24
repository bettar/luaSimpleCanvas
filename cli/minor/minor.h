// Alex Bettarini - 2025
#include <string>
#include <vector>
#pragma once

struct oneNote {
	int str;
	int fret;
	std::string label;
	bool root = false;
	bool stretch = false; // show in red streched hand position to reach the next note
};

extern const std::vector<std::vector<struct oneNote>> allScales;

struct scaleInfo {
	std::string name;
	std::string alterations; // sharps and flats
	int nFretsScale[4] = {8,8,8,8};
};

extern const std::vector<struct scaleInfo> keyInfo;
