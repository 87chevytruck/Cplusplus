#pragma once
#include "weapon.h"

// WARNING
/*
There is an example subclass included... delete it if you want to try it without reference
Please note, this is a bare bones subclass. It only includes enough to get you started
*/



// Sub Classes
class NEXT : public Mecha {

public:
	// Default Constructor
	NEXT() {
		mechaName = "Nomad";
		variant = "N/A";
		type = "NEXT";
		power = 100;
	}
	// Constructor
	NEXT(std::string mn, std::string va, int pwr = 100) {
		mechaName = mn;
		variant = va;
		type = "NEXT";
		power = pwr;
	}

};


class MobileSuit : public Mecha {

public:
	// Default Constructor
	MobileSuit() {
		mechaName = "Nomad";
		variant = "N/A";
		type = "Mobile Suit";
		power = 100;
	}
	// Constructor
	MobileSuit(std::string mn, std::string va, int pwr = 100) {
		mechaName = mn;
		variant = va;
		type = "Mobile Suit";
		power = pwr;
	}

};

class Terminator : public Mecha {
public:
	// Default Constructor
	Terminator() {
		mechaName = "T-9000 Terminator";
		variant = "N/A";
		type = "Destroyer";
		power = 100;
	}
	// Constructor
	Terminator(std::string mn, std::string va, int pwr = 100) {
		mechaName = mn;
		variant = va;
		type = "Destroyer";
		power = pwr;
	}

};