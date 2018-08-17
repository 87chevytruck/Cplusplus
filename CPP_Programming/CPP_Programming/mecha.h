
#pragma once
#include <string>
#include <iostream>
#include "weapon.h"
// TODO: You will need to inherit your mecha from the class Mecha first... be sure to override the functions if you need to.

// Base Classes
class Mecha {
private:
	Weapon LHandW;
	Weapon RHandW;
	Weapon LBackW;
	Weapon RBackW;

protected:
	std::string mechaName;
	std::string variant;
	std::string type;

	int hitPoints;// indicates total health remaining
	int power; // indicates power per turn... this value should never be modified after it's set.
public:
	// Default constructor... subclass should handle construction
	Mecha() {}

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

	// Get weapon name for Mech
	void get_leftHand_weapon() {
		std::cout << "Left Hand Weapon:  ";
		std::cout << LHandW.getWPNname();
		std::cout << " Selected" << std::endl;
	}
	void get_rightHand_weapon() {
		std::cout << "Right Hand Weapon:  ";
		std::cout << RHandW.getWPNname();
		std::cout << " Selected" << std::endl;
	}
	void get_leftBack_weapon() {
		std::cout << "Left Back Weapon:  ";
		std::cout << LBackW.getWPNname();
		std::cout << " Selected" << std::endl;
	}
	void get_rightBack_weapon() {
		std::cout << "Right Back Weapon:  ";
		std::cout << LBackW.getWPNname();
		std::cout << " Selected" << std::endl;
	}


	bool setHP(int hp) {
		// units can only have 2000 health
		if (hp <= 2000) {
			hitPoints = hp;
			return true;
		}
		return false;
	}
	bool setPWR(int pwr) {
		//units can only have 100 power
		if (pwr <= 100) {
			power = pwr;
			return true;
		}
		return false;
	}

	// allows dynamic use of weapon costs for pointer player
	int leftHandCost() {

		return LHandW.getCost();
	}
	int rightHandCost() {

		return RHandW.getCost();
	}
	int leftBackCost() {

		return LBackW.getCost();
	}
	int rightBackCost() {

		return LBackW.getCost();
	}

	// allows dynamic use of weapon damage for pointer player
	int leftHandDMG() {

		return LHandW.getDMG();
	}
	int rightHandDMG() {

		return RHandW.getDMG();
	}
	int leftBackDMG() {

		return LBackW.getDMG();
	}
	int rightBackDMG() {

		return LBackW.getDMG();
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

	////////////////////////////////////////////////////
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

		power = power - powerDraw;  //calculates power draw for weapon use
	}
	void rechargePWR(int powerCharge) {

		power = powerCharge;  //used for recharging mech for next turn
	}
	int computeHP() {
		
		return hitPoints;
	}

};