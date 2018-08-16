#pragma once
/*
This one is already built for you... feel free to add to it.
Utilize the damage in either a method (pref in mecha_sub) or main() to determine how muchh damage you do on an enemy mech
Ensure power is being subtracted by cost after every action. Prevent action if power is too low for action (this can be done via method (pref in mecha sub)  or main)
*/




class Weapon {
private:
	std::string weaponName;
	std::string weaponType;
	int damage;					// How much damage this weapon does
	int cost;					// Cost to use weapon on turn
public:
	Weapon() {}
	Weapon(std::string name, std::string type, int dmg, int ct) {
		weaponName = name;
		weaponType = type;
		damage = dmg;
		cost = ct;
	}
	void display_weapon_stats() {
		std::cout << "Model: " << weaponName << std::endl;
		std::cout << "Type: " << weaponType << std::endl;
		std::cout << "Damage: " << damage << std::endl;
		std::cout << "Cost: " << cost << std::endl;
	}
	int getDMG() {
		
		return damage;
	}

	int getCost() {

		return cost;
	}

	std::string getWPNname() {

		return weaponName;
	}

};
