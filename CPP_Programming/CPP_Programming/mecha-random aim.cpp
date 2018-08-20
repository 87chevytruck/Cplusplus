
#include "mecha.h"
#include "mecha_subs.h"
#include "weapon.h"
#include <string>
#include <sstream>
#include <time.h>
#include <chrono>
#include <thread>


// Default Mecha for initial assignment to player1 and player2
Mecha *player1;
Mecha *player2;

void player1_accuracy(int y);
void player2_accuracy(int y);
void weapon_action();
void weapon_action_reverse();

int main() {
	// TODO: Create your weapons here. 
	// Don't over think this step... just create weapon objects. One weapon can be used on multiple mechs
	Weapon BFF1(".50 Cal Sniper", "Rifle", 100, 20);
	Weapon BFF2(".50 Cal Full Auto", "Assault Rifle", 50, 10);
	Weapon MSAC1("SALINE05", "Spread Missile", 200, 50);
	Weapon MC1("Machine Cannon", "Automatic Cannon", 300, 50);
	Weapon TNM1("Tactical Nuclear Missile", "Missile Launcher", 600, 100);

	srand(time(NULL)); //initializes random seed for use in "random" weapon damage





	// TODO: Create your sub mechs here
	// Ensure you also pass your weapons to your mechs... you can do this via on sub mech creation or through a setter method
	// Don't overthink this one either... reference course and example if needed. 
	// White Glint
	NEXT WG("White Glint", "main", 300);
	bool validHP = false;
	while (!validHP) {
		// update with user input
		validHP = WG.setHP(2000);
	}
	WG.set_leftHand_weapon(TNM1);
	WG.set_rightHand_weapon(BFF1);
	WG.set_leftBack_weapon(MSAC1);
	WG.set_rightBack_weapon(MSAC1);

	// Kshatriya
	MobileSuit Ksh("Kshatriya", "NZ-666");
	bool validHP2 = false;
	while (!validHP2) {
		// update with user input
		validHP2 = Ksh.setHP(2500);
	}
	Ksh.set_leftHand_weapon(MC1);
	Ksh.set_rightHand_weapon(MC1);
	Ksh.set_leftBack_weapon(BFF1);
	Ksh.set_rightBack_weapon(BFF1);

	//T9000 Terminator
	Terminator T9("T-9000 Terminator", "Cybernetic System", 300);
	bool validHP3 = false;
	while (!validHP3) {
		//update with user input
		validHP3 = T9.setHP(2000);
	}
	T9.set_leftBack_weapon(TNM1);
	T9.set_rightBack_weapon(MSAC1);
	T9.set_leftHand_weapon(MC1);
	T9.set_rightHand_weapon(MC1);


	// Default Mecha for initial assignment to player1 and player2
	player1 = (NEXT *)&WG;
	player2 = (MobileSuit *)&Ksh;


	// Now we can do our main logic
	WG.display_stats();
	Ksh.display_stats();
	T9.display_stats();


	
	std::string player1input;
	std::string player2input;
	int count = 0;


	//allow user 1 to select a Mecha
	while (count == 0)
	{
		std::cout << "\t\tPlayer 1:  Select your Mecha." << std::endl;
		std::cout << "\t\tType \" WG \" to select the White Glint Mecha." << std::endl;
		std::cout << "\t\tType \" KSH \" to select the Kshatriya Mecha." << std::endl;
		std::cout << "\t\tType \" T9 \" to select the T-9000 Terminator Mecha." << std::endl;
		std::cout << "\t\tType \" exit \" to exit." << std::endl;
		std::getline(std::cin, player1input);
		if (player1input == " WG " || player1input == " wg " || player1input == "WG" || player1input == "wg")
		{
			//assign player1 to the White Glint Mecha
			player1 = (NEXT *)&WG;
			std::cout << "\t\tPlayer 1 is now White Glint Mecha\n" << std::endl;

			count++;
		}
		else if (player1input == " KSH " || player1input == " ksh " || player1input == "KSH" || player1input == "ksh")
		{
			//assign player1 to the Kshatriya Mecha
			player1 = (MobileSuit *)&Ksh;
			std::cout << "\t\tPlayer 1 is now Kshatriya Mecha\n" << std::endl;
			count++;
		}
		else if (player1input == " T9 " || player1input == " t9 " || player1input == "t9" || player1input == "T9")
		{
			//assign player1 to the T-9000 Terminator Mecha
			player1 = (Terminator *)&T9;
			std::cout << "\t\tPlayer 1 is now T-9000 Terminator Mecha\n" << std::endl;
			count++;
		}
		else if (player1input == " exit " || player1input == "exit" || player1input == " Exit " || player1input == "Exit")
		{
			count++;
			return 0;
		}
		else
		{
			std::cout << "\t\tERROR:  Invalid response for Player 1.  Please try again." << std::endl;
		}
	}

	count = 0;

	//allow user 2 to select a Mecha
	while (count == 0)
	{
		std::cout << "\t\tPlayer 2:  Select your Mecha." << std::endl;
		std::cout << "\t\tType \" WG \" to select the White Glint Mecha." << std::endl;
		std::cout << "\t\tType \" KSH \" to select the Kshatriya Mecha." << std::endl;
		std::cout << "\t\tType \" T9 \" to select the T-9000 Terminator Mecha." << std::endl;
		std::cout << "\t\tType \" exit \" to exit." << std::endl;
		std::getline(std::cin, player2input);
		if (player2input == " WG " || player2input == " wg " || player2input == "WG" || player2input == "wg")
		{
			//assign player2 to the White Glint Mecha
			if (player1input != " WG " && player1input != " wg " && player1input != "WG" && player1input != "wg")
			{
				player2 = (NEXT *)&WG;
				std::cout << "\t\tPlayer 2 is now White Glint Mecha\n" << std::endl;
				count++;
			}
			else
			{
				std::cout << "\t\tERROR:  This Mecha is in use already by Player 1." << std::endl;
			}
		}
		else if (player2input == " KSH " || player2input == " ksh " || player2input == "KSH" || player2input == "ksh")
		{
			//assign player2 to the Kshatriya Mecha
			if (player1input != " KSH " && player1input != " ksh " && player1input != "KSH" && player1input != "ksh")
			{
			player2 = (MobileSuit *)&Ksh;
			std::cout << "\t\tPlayer 2 is now Kshatriya Mecha\n" << std::endl;
			count++;
			}
			else
			{
				std::cout << "\t\tERROR:  This Mecha is in use already by Player 1." << std::endl;
			}
		}
		else if (player2input == " T9 " || player2input == " t9 " || player2input == "t9" || player2input == "T9")
		{
			//assign player2 to the T-9000 Terminator Mecha
			if (player1input != " T9 " && player1input != " t9 " && player1input != "t9" && player1input != "T9")
			{
			player2 = (Terminator *)&T9;
			std::cout << "\t\tPlayer 2 is now T-9000 Terminator Mecha\n" << std::endl;
			count++;
			}
			else
			{
				std::cout << "\t\tERROR:  This Mecha is in use already by Player 1." << std::endl;
			}
			
		}
		else if (player2input == " exit " || player2input == "exit" || player2input == " Exit " || player2input == "Exit")
		{
			count++;
			return 0;
		}
		else
		{
			std::cout << "\t\tERROR:  Invalid response for Player 2.  Please try again." << std::endl;
		}
	}

	//end the game if a player's mech hits <= 0
	while (player1->computeHP() > 0 && player2->computeHP() > 0)
	{

		//allow users to take turns attacking
		//----allow users to decide which weapon to use during the their turn
	
	
		player1->rechargePWR(100);  //initializes and recharges power each time players take turns
		player2->rechargePWR(100);  //initializes and recharges power each time players take turns

		while (player1->getPWR() >= 1)	//prevent actions if user runs out of power
		{
			//prints player menu
			std::cout << "\n\n\t\tPlayer 1, please select from an option below: (type the number of the option)" << std::endl;
			std::cout << "\t\t1 - Use Left Hand Weapon";
			player1->get_leftHand_weapon();
			std::cout << std::endl;
			std::cout << "\t\t2 - Use Right Hand Weapon";
			player1->get_rightHand_weapon();
			std::cout << std::endl;
			std::cout << "\t\t3 - Use Left Back Weapon";
			player1->get_leftBack_weapon();
			std::cout << std::endl;
			std::cout << "\t\t4 - Use Right Back Weapon";
			player1->get_rightBack_weapon();
			std::cout << std::endl;
			std::cout << "\t\t5 - Print Current Mech Stats            N/A" << std::endl;
			std::cout << "\t\t6 - End player turn early               N/A" << std::endl;

			int menuSelection = 0;

			//get input
			while (1)
			{
				std::string input;
				std::getline(std::cin, input);
				std::stringstream myStream(input);
				if (myStream >> menuSelection)
				{
					break;
				}
				std::cout << "\t\tInvalid Input, please try again" << std::endl;
			}


			switch (menuSelection)
			{
			case 1: //Select Left Hand Weapon
			{
				if (player1->getPWR() < player1->leftHandCost())	//prevent actions if user runs out of power
				{
					std::cout << "\t\tERROR:  Not enough power available to use this weapon." << std::endl;
					break;
				}
				weapon_action();
				std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
				player1->get_leftHand_weapon();  // displays which weapon was selected
				std::cout << " Selected" << std::endl;
				std::cout << "\n\t\tPlayer 1 Before Attack:  ";
				player1->printPWR();  // displays current power
				player1->drawPWR(player1->leftHandCost());  //calculates power draw 
				std::cout << "\n\t\tPlayer 1 After Attack:  ";
				player1->printPWR();  // displays current power
				std::cout << "\n---------------------------------------------------------------------------" << std::endl;
				std::cout << "\n\t\tPlayer 2 Before Attack:  ";
				player2->getHP(); //displays remaing health for enemy

				player1_accuracy(player1->leftHandDMG());  //apply accuracy function to compute enemy damage
				//player2->computeDamageReceived(player1->leftHandDMG());  //applies damage to other player
				std::cout << "\n\t\tPlayer 2 After Attack:  ";
				player2->getHP(); //displays remaing health for enemy
				std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n" << std::endl;
				break;
			}

			case 2: // Select Right Hand Weapon
			{
				if (player1->getPWR() < player1->rightHandCost())	//prevent actions if user runs out of power
				{
					std::cout << "\t\tERROR:  Not enough power available to use this weapon." << std::endl;
					break;
				}

				weapon_action();

				std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
				player1->get_rightHand_weapon();  // displays which weapon was selected
				std::cout << " Selected" << std::endl;
				std::cout << "\n\t\tPlayer 1 Before Attack:  ";
				player1->printPWR();  // displays current power
				player1->drawPWR(player1->rightHandCost());  //calculates power draw 
				std::cout << "\n\t\tPlayer 1 After Attack:  ";
				player1->printPWR();  // displays current power
				std::cout << "\n-----------------------------------------------------------------" << std::endl;
				std::cout << "\n\t\tPlayer 2 Before Attack:  ";
				player2->getHP(); //displays remaing health for enemy

				player1_accuracy(player1->rightHandDMG());  //apply accuracy function to compute enemy damage
				//player2->computeDamageReceived(player1->rightHandDMG());  //applies damage to other player
				std::cout << "\n\t\tPlayer 2 After Attack:  ";
				player2->getHP(); //displays remaing health for enemy
				std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n" << std::endl;
				break;
			}
			case 3: //Select Left Back Weapon
			{
				if (player1->getPWR() < player1->leftBackCost())	//prevent actions if user runs out of power
				{
					std::cout << "\t\tERROR:  Not enough power available to use this weapon." << std::endl;
					break;
				}
				weapon_action();
				std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
				player1->get_leftBack_weapon();  // displays which weapon was selected
				std::cout << " Selected" << std::endl;
				std::cout << "\n\t\tPlayer 1 Before Attack:  ";
				player1->printPWR();  // displays current power
				player1->drawPWR(player1->leftBackCost());  //calculates power draw 
				std::cout << "\n\t\tPlayer 1 After Attack:  ";
				player1->printPWR();  // displays current power
				std::cout << "\n-----------------------------------------------------------------" << std::endl;
				std::cout << "\n\t\tPlayer 2 Before Attack:  ";
				player2->getHP(); //displays remaing health for enemy

				player1_accuracy(player1->leftBackDMG());  //apply accuracy function to compute enemy damage
				//player2->computeDamageReceived(player1->leftBackDMG());  //applies damage to other player
				std::cout << "\n\t\tPlayer 2 After Attack:  ";
				player2->getHP(); //displays remaing health for enemy
				std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n" << std::endl;
				break;
			}
			case 4: //Select Right Back Weapon
			{
				if (player1->getPWR() < player1->rightBackCost())	//prevent actions if user runs out of power
				{
					std::cout << "\t\tERROR:  Not enough power available to use this weapon." << std::endl;
					break;
				}
				weapon_action();
				std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
				player1->get_rightBack_weapon();  // displays which weapon was selected
				std::cout << " Selected" << std::endl;
				std::cout << "\n\t\tPlayer 1 Before Attack:  ";
				player1->printPWR();  // displays current power
				player1->drawPWR(player1->rightBackCost());  //calculates power draw 
				std::cout << "\n\t\tPlayer 1 After Attack:  ";
				player1->printPWR();  // displays current power
				std::cout << "\n-----------------------------------------------------------------" << std::endl;
				std::cout << "\n\t\tPlayer 2 Before Attack:  ";
				player2->getHP(); //displays remaing health for enemy

				player1_accuracy(player1->rightBackDMG());  //apply accuracy function to compute enemy damage
				//player2->computeDamageReceived(player1->rightBackDMG());  //applies damage to other player
				std::cout << "\n\t\tPlayer 2 After Attack:  ";
				player2->getHP(); //displays remaing health for enemy
				std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n" << std::endl;
				break;
			}
			case 5:  // Print Current Mech Stats
			{
				player1->display_stats();
				player1->getHP(); //displays remaing health for current player
				break;
			}
			case 6: // End turn early
			{  	//allow user to end their turn regardless of how much power is left
				std::cout << "\t\tPlayer 1 has chosen to end their turn." << std::endl;
				player1->drawPWR(1000);
				break;
			}
			}
		}

		if (player1->computeHP() >= 1 && player2->computeHP() <= 0)
		{
			//player1 wins
			std::cout << "\t\t\n\n+*+*+*+*+*+*+*+*+*+*+" << std::endl;
			std::cout << "\t\t|                   |" << std::endl;
			std::cout << "\t\t|  Player 1 WINs!!  |" << std::endl;
			std::cout << "\t\t|                   |" << std::endl;
			std::cout << "\t\t+*+*+*+*+*+*+*+*+*+*+\n\n" << std::endl;
			break;
		}

		
		while (player2->getPWR() >= 1)	//prevent actions if user runs out of power
		{
			//prints player menu
			std::cout << "\n\n\t\tPlayer 2, please select from an option below: (type the number of the option)" << std::endl;
			std::cout << "\t\t1 - Use Left Hand Weapon" << std::endl;
			std::cout << "\t\t2 - Use Right Hand Weapon" << std::endl;
			std::cout << "\t\t3 - Use Left Back Weapon" << std::endl;
			std::cout << "\t\t4 - Use Right Back Weapon" << std::endl;
			std::cout << "\t\t5 - Print Current Mech Stats" << std::endl;
			std::cout << "\t\t6 - End player turn early" << std::endl;

			int menuSelection = 0;

			//get input
			while (1)
			{
				std::string input;
				std::getline(std::cin, input);
				std::stringstream myStream(input);
				if (myStream >> menuSelection)
				{
					break;
				}
				std::cout << "\t\tInvalid Input, please try again" << std::endl;
			}


			switch (menuSelection)
			{
			case 1: //Select Left Hand Weapon
			{
				if (player2->getPWR() < player2->leftHandCost())	//prevent actions if user runs out of power
				{
					std::cout << "\t\tERROR:  Not enough power available to use this weapon." << std::endl;
					break;
				}
				weapon_action_reverse();
				std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
				player2->get_leftHand_weapon();  // displays which weapon was selected
				std::cout << " Selected" << std::endl;
				std::cout << "\n\t\tPlayer 2 Before Attack:  ";
				player2->printPWR();  // displays current power
				player2->drawPWR(player2->leftHandCost());  //calculates power draw 
				std::cout << "\n\t\tPlayer 2 After Attack:  ";
				player2->printPWR();  // displays current power
				std::cout << "\n-----------------------------------------------------------------" << std::endl;
				std::cout << "\n\t\tPlayer 1 Before Attack:  ";
				player1->getHP(); //displays remaing health for enemy

				player2_accuracy(player2->leftHandDMG());  //apply accuracy function to compute enemy damage
				//player1->computeDamageReceived(player2->leftHandDMG());  //applies damage to other player
				std::cout << "\n\t\tPlayer 1 After Attack:  ";
				player1->getHP(); //displays remaing health for enemy
				std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n" << std::endl;
				break;
			}

			case 2: // Select Right Hand Weapon
			{
				if (player2->getPWR() < player2->rightHandCost())	//prevent actions if user runs out of power
				{
					std::cout << "\t\tERROR:  Not enough power available to use this weapon." << std::endl;
					break;
				}
				weapon_action_reverse();
				std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
				player2->get_rightHand_weapon();  // displays which weapon was selected
				std::cout << " Selected" << std::endl;
				std::cout << "\n\t\tPlayer 2 Before Attack:  ";
				player2->printPWR();  // displays current power
				player2->drawPWR(player2->rightHandCost());  //calculates power draw 
				std::cout << "\n\t\tPlayer 2 After Attack:  ";
				player2->printPWR();  // displays current power
				std::cout << "\n-----------------------------------------------------------------" << std::endl;
				std::cout << "\n\t\tPlayer 1 Before Attack:  ";
				player1->getHP(); //displays remaing health for enemy

				player2_accuracy(player2->rightHandDMG());  //apply accuracy function to compute enemy damage
				//player1->computeDamageReceived(player2->rightHandDMG());  //applies damage to other player
				std::cout << "\n\t\tPlayer 1 After Attack:  ";
				player1->getHP(); //displays remaing health for enemy
				std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n" << std::endl;
				break;
			}
			case 3: //Select Left Back Weapon
			{
				if (player2->getPWR() < player2->leftBackCost())	//prevent actions if user runs out of power
				{
					std::cout << "\t\tERROR:  Not enough power available to use this weapon." << std::endl;
					break;
				}
				weapon_action_reverse();
				std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
				player2->get_leftBack_weapon();  // displays which weapon was selected
				std::cout << " Selected" << std::endl;
				std::cout << "\n\t\tPlayer 2 Before Attack:  ";
				player2->printPWR();  // displays current power
				player2->drawPWR(player2->leftBackCost());  //calculates power draw 
				std::cout << "\n\t\tPlayer 2 After Attack:  ";
				player2->printPWR();  // displays current power
				std::cout << "\n-----------------------------------------------------------------" << std::endl;
				std::cout << "\n\t\tPlayer 1 Before Attack:  ";
				player1->getHP(); //displays remaing health for enemy

				player2_accuracy(player2->leftBackDMG());  //apply accuracy function to compute enemy damage
				//player1->computeDamageReceived(player2->leftBackDMG());  //applies damage to other player
				std::cout << "\n\t\tPlayer 1 After Attack:  ";
				player1->getHP(); //displays remaing health for enemy
				std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n" << std::endl;
				break;
			}
			case 4: //Select Right Back Weapon
			{
				if (player2->getPWR() < player2->rightBackCost())	//prevent actions if user runs out of power
				{
					std::cout << "\t\tERROR:  Not enough power available to use this weapon." << std::endl;
					break;
				}
				weapon_action_reverse();
				std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
				player2->get_rightBack_weapon();  // displays which weapon was selected
				std::cout << " Selected" << std::endl;
				std::cout << "\n\t\tPlayer 1 Before Attack:  ";
				player2->printPWR();  // displays current power
				player2->drawPWR(player2->rightBackCost());  //calculates power draw 
				std::cout << "\n\t\tPlayer 1 After Attack:  ";
				player2->printPWR();  // displays current power
				std::cout << "\n-----------------------------------------------------------------" << std::endl;
				std::cout << "\n\t\tPlayer 2 Before Attack:  ";
				player1->getHP(); //displays remaing health for enemy

				player2_accuracy(player2->rightBackDMG());  //apply accuracy function to compute enemy damage
				//player1->computeDamageReceived(player2->rightBackDMG());  //applies damage to other player
				std::cout << "\n\t\tPlayer 2 After Attack:  ";
				player1->getHP(); //displays remaing health for enemy
				std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n" << std::endl;
				break;
			}
			case 5:  // Print Current Mech Stats
			{
				player2->display_stats();
				player2->getHP(); //displays remaing health for current player
				break;
			}
			case 6: // End turn early
			{  	//allow user to end their turn regardless of how much power is left
				std::cout << "\t\tPlayer 2 has chosen to end their turn." << std::endl;
				player2->drawPWR(1000);
				break;
			}
			}
		}

		if (player1->computeHP() <= 0 && player2->computeHP() >= 1)
		{
			//player2 wins
			std::cout << "\n\n\t\t+*+*+*+*+*+*+*+*+*+*+" << std::endl;
			std::cout << "\t\t|                   |" << std::endl;
			std::cout << "\t\t|  Player 2 WINs!!  |" << std::endl;
			std::cout << "\t\t|                   |" << std::endl;
			std::cout << "\t\t+*+*+*+*+*+*+*+*+*+*+\n\n" << std::endl;
			break;
		}

	}


	getchar();
	getchar();

	return 0;
}

void player1_accuracy(int y)  //y is the weapon being used, specifically the "damage" from that weapon
{
	if (y > 100)  //checks it weapon damage is more than 100 (function is meant for large weapons)
	{
		int x = (rand() % 10 + 1);  //generates random number between 1 and 10 (uses the srand of time command)
		if (x <= 4)  //if random number is less than or equal to 4, calculate damage to 30% of max damage
		{
			player2->computeDamageReceived(y * .30);
			std::cout << "\t\t============================================" << std::endl;
			std::cout << "\t\t  Enemy Grazed! Only 30% damage delivered!" << std::endl;
			std::cout << "\t\t============================================\n" << std::endl;
		}
		else if (x >= 7)  //if random number is greater than or equal to 7, calculate damage to 70% of max damage
		{
			player2->computeDamageReceived(y * .70);
			std::cout << "\t\t=============================================" << std::endl;
			std::cout << "\t\t  Enemy Wounded! Only 70% damage delivered!" << std::endl;
			std::cout << "\t\t=============================================\n" << std::endl;
		}
		else  //if random number is 5 or 6, calculate damage to be max damage
		{
			player2->computeDamageReceived(y);
			std::cout << "\t\t========================================" << std::endl;
			std::cout << "\t\t  PERFECT SHOT! 100% damage delivered!" << std::endl;
			std::cout << "\t\t========================================\n" << std::endl;
		}

	}
	else  //if max damage is 100 or less, use max damage (represents very accurate weapons)
	{
		player2->computeDamageReceived(y);
		std::cout << "\t\t========================================" << std::endl;
		std::cout << "\t\t  PERFECT SHOT! 100% damage delivered!" << std::endl;
		std::cout << "\t\t========================================\n" << std::endl;
	}
}

void player2_accuracy(int y)  //y is the weapon being used, specifically the "damage" from that weapon
{
	if (y > 100)  //checks it weapon damage is more than 100 (function is meant for large weapons)
	{
		int x = (rand() % 10 + 1);  //generates random number between 1 and 10 (uses the srand of time command)
		if (x <= 4)  //if random number is less than or equal to 4, calculate damage to 30% of max damage
		{
			player1->computeDamageReceived(y * .30);
			std::cout << "\t\t============================================" << std::endl;
			std::cout << "\t\t  Enemy Grazed! Only 30% damage delivered!" << std::endl;
			std::cout << "\t\t============================================\n" << std::endl;
		}
		else if (x >= 7)  //if random number is greater than or equal to 7, calculate damage to 70% of max damage
		{
			player1->computeDamageReceived(y * .70);
			std::cout << "\t\t=============================================" << std::endl;
			std::cout << "\t\t  Enemy Wounded! Only 70% damage delivered!" << std::endl;
			std::cout << "\t\t=============================================\n" << std::endl;
		}
		else  //if random number is 5 or 6, calculate damage to be max damage
		{
			player1->computeDamageReceived(y);
			std::cout << "\t\t========================================" << std::endl;
			std::cout << "\t\t  PERFECT SHOT! 100% damage delivered!" << std::endl;
			std::cout << "\t\t========================================\n" << std::endl;
		}

	}
	else  //if max damage is 100 or less, use max damage (represents very accurate weapons)
	{
		player1->computeDamageReceived(y);
		std::cout << "\t\t========================================" << std::endl;
		std::cout << "\t\t  PERFECT SHOT! 100% damage delivered!" << std::endl;
		std::cout << "\t\t========================================\n" << std::endl;
	}
}

void weapon_action()
{
	system("CLS");
	std::this_thread::sleep_for(std::chrono::milliseconds(500));

	std::cout << "*********************************************************************************" << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(500));
	std::cout << "Firing in ";
	std::this_thread::sleep_for(std::chrono::milliseconds(800));
	std::cout << "3 ";
	std::this_thread::sleep_for(std::chrono::milliseconds(800));
	std::cout << "2 ";
	std::this_thread::sleep_for(std::chrono::milliseconds(800));
	std::cout << "1 " << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(800));

	std::cout << "\t\tPlayer 1 ~~~~+===>                                        Player 2" << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(250));
	std::cout << "\t\tPlayer 1       ~~~~+===>                                  Player 2" << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(250));
	std::cout << "\t\tPlayer 1             ~~~~+===>                            Player 2" << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(250));
	std::cout << "\t\tPlayer 1                   ~~~~+===>                      Player 2" << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(250));
	std::cout << "\t\tPlayer 1                         ~~~~+===>                Player 2" << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(250));
	std::cout << "\t\tPlayer 1                               ~~~~+===>          Player 2" << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(250));
	std::cout << "\t\tPlayer 1                                     ~~~~+===>    Player 2" << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(250));
	std::cout << "\t\tPlayer 1                                           ~~~~+===>ayer 2" << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(250));
	std::cout << "\t\tPlayer 1                                                 ~~~~+===>" << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(250));
	std::cout << "\t\tPlayer 1                                                  XXXXXXXX" << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(250));
	std::cout << "*********************************************************************************" << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(500));
}
void weapon_action_reverse()
{
	system("CLS");
	std::this_thread::sleep_for(std::chrono::milliseconds(500));

	std::cout << "*********************************************************************************" << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(500));
	std::cout << "Firing in ";
	std::this_thread::sleep_for(std::chrono::milliseconds(800));
	std::cout << "3 ";
	std::this_thread::sleep_for(std::chrono::milliseconds(800));
	std::cout << "2 ";
	std::this_thread::sleep_for(std::chrono::milliseconds(800));
	std::cout << "1 " << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(800));

	std::cout << "\t\tPlayer 1                                        <===+~~~~ Player 2" << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(250));
	std::cout << "\t\tPlayer 1                                   <===+~~~~      Player 2" << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(250));
	std::cout << "\t\tPlayer 1                             <===+~~~~            Player 2" << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(250));
	std::cout << "\t\tPlayer 1                      <===+~~~~                   Player 2" << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(250));
	std::cout << "\t\tPlayer 1                <===+~~~~                         Player 2" << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(250));
	std::cout << "\t\tPlayer 1          <===+~~~~                               Player 2" << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(250));
	std::cout << "\t\tPlayer 1   <===+~~~~                                      Player 2" << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(250));
	std::cout << "\t\tPlay<===+~~~~                                             Player 2" << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(250));
	std::cout << "\t\t<===+~~~~                                                 Player 2" << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(250));
	std::cout << "\t\tXXXXXXXX                                                  Player 2" << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(250));
	std::cout << "*********************************************************************************" << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(500));
}
