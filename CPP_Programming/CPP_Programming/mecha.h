
#pragma once
#include <string>
#include <iostream>
// TODO: You will need to inherit your mecha from the class Mecha first... be sure to override the functions if you need to.

// Base Classes
class Mecha {
protected:
	std::string mechaName;
	std::string variant;
	std::string type;

	int hitPoints;// indicates total health remaining
	int power; // indicates power per turn... this value should never be modified after it's set.
public:
	// Default constructor... subclass should handle construction
	Mecha() {}
	// You will want to either override this function to add weapon and specific stats... or just utilize it as is and create a new method inside your sub mecha
	virtual void display_main_stats() {
		std::cout << "Model: " << mechaName << std::endl;
		std::cout << "Variant: " << variant << std::endl;
		std::cout << "Type : " << type << std::endl;
	}
	/*
	Use this method if you want to determine how much damage your mecha takes
	This can be either really simple (just amount of damage enemy mech does to you...
	Or you can go in on this and do damage types and such.
	*/
	void computeDamageReceived(int damagePts) {
		
		hitPoints = hitPoints - damagePts;

	}
	// Bare minimum... use this to see if your mech is dead yet
	int getHP() {
		std::cout << "\nHit Points Remaining:  " << hitPoints << std::endl;
		return hitPoints;
	}
	int printPWR() {
		std::cout << "\nPower Remaining:  " << power << std::endl;
		return power;
	}
	int getPWR() {

		return power;
	}
	void drawPWR(int powerDraw) {

		power = power - powerDraw;
	}
	void rechargePWR(int powerCharge) {

		power = powerCharge;
	}
	int computeHP() {
		
		return hitPoints;
	}

};