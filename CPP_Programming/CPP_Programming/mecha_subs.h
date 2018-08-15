#pragma once
#include "weapon.h"

// WARNING
/*
There is an example subclass included... delete it if you want to try it without reference
Please note, this is a bare bones subclass. It only includes enough to get you started
*/



// Sub Classes
class NEXT : public Mecha {
private:
	Weapon LHandW;
	Weapon RHandW;
	Weapon LBackW;
	Weapon RBackW;

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
	// Below sets weapons, take weapon object
	void set_leftHand_weapon(Weapon wp) {
		LHandW = wp;
	}
	void set_rightHand_weapon(Weapon wp) {
		RHandW = wp;
	}
	void set_leftBack_weapon(Weapon wp) {
		LBackW = wp;
	}
	void set_rightBack_weapon(Weapon wp) {
		RBackW = wp;
	}
	bool setHP(int hp) {
		// NEXT units can only have 2000 health
		if (hp <= 2000) {
			hitPoints = hp;
			return true;
		}
		return false;
	}
	void display_stats() {
		std::cout << "********* Displaying Stats *********" << std::endl;
		display_main_stats();
		std::cout << "===== WEAPONS =====\n" << std::endl;
		std::cout << "Left Hand Weapon:" << std::endl;
		LHandW.display_weapon_stats();
		std::cout << "\nRight Hand Weapon:" << std::endl;
		RHandW.display_weapon_stats();
		std::cout << "\nLeft Back Weapon: " << std::endl;
		LBackW.display_weapon_stats();
		std::cout << "\nRight Back Weapon: " << std::endl;
		RBackW.display_weapon_stats();
		std::cout << "\n\n\n\n";

	}
};


class MobileSuit : public Mecha {
	// This mech only has two weapons
private:
	Weapon LHandW;
	Weapon RHandW;

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
	// Below sets weapons, take weapon object
	void set_leftHand_weapon(Weapon wp) {
		LHandW = wp;
	}
	void set_rightHand_weapon(Weapon wp) {
		RHandW = wp;
	}
	bool setHP(int hp) {
		// Mobile suits can only have 500 health
		if (hp <= 500) {
			hitPoints = hp;
			return true;
		}
		return false; // catch this in main, recall set HP with a valid number
	}
		void display_stats()
		{
			std::cout << "********* Displaying Stats *********" << std::endl;
			display_main_stats();
			std::cout << "===== WEAPONS =====\n" << std::endl;
			std::cout << "Left Hand Weapon:" << std::endl;
			LHandW.display_weapon_stats();
			std::cout << "\nRight Hand Weapon:" << std::endl;
			RHandW.display_weapon_stats();
			//	std::cout << "\nLeft Back Weapon: " << std::endl;
			//	LBackW.display_weapon_stats();
			//	std::cout << "\nRight Back Weapon: " << std::endl;
			//	RBackW.display_weapon_stats();
			std::cout << "\n\n\n\n";
		}

};

class Terminator : public Mecha {
private:
	Weapon LHandW;
	Weapon RHandW;
	Weapon LBackW;
	Weapon RBackW;

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
	// Below sets weapons, take weapon object
	void set_leftHand_weapon(Weapon wp) {
		LHandW = wp;
	}
	void set_rightHand_weapon(Weapon wp) {
		RHandW = wp;
	}
	void set_leftBack_weapon(Weapon wp) {
		LBackW = wp;
	}
	void set_rightBack_weapon(Weapon wp) {
		RBackW = wp;
	}
	bool setHP(int hp) {
		// Terminator units can only have 2000 health
		if (hp <= 2000) {
			hitPoints = hp;
			return true;
		}
		return false;
	}
	void display_stats() {
		std::cout << "********* Displaying Stats *********" << std::endl;
		display_main_stats();
		std::cout << "===== WEAPONS =====\n" << std::endl;
		std::cout << "Left Hand Weapon:" << std::endl;
		LHandW.display_weapon_stats();
		std::cout << "\nRight Hand Weapon:" << std::endl;
		RHandW.display_weapon_stats();
		std::cout << "\nLeft Back Weapon: " << std::endl;
		LBackW.display_weapon_stats();
		std::cout << "\nRight Back Weapon: " << std::endl;
		RBackW.display_weapon_stats();
		std::cout << "\n\n\n\n";

	}
};