
#include "mecha.h"
#include "mecha_subs.h"
#include "weapon.h"
#include <string>
#include <sstream>

int main() {
	// TODO: Create your weapons here. 
	// Don't over think this step... just create weapon objects. One weapon can be used on multiple mechs
	Weapon BFF1(".50 Cal Sniper", "Rifle", 100, 20);
	Weapon BFF2(".50 Cal Full Auto", "Assault Rifle", 50, 10);
	Weapon MSAC1("SALINE05", "Spread Missile", 200, 50);
	Weapon MC1("Machine Cannon", "Automatic Cannon", 300, 50);
	Weapon TNM1("Tactical Nuclear Missile", "Missile Launcher", 600, 100);


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
		validHP2 = Ksh.setHP(500);
	}
	Ksh.set_leftHand_weapon(MC1);
	Ksh.set_rightHand_weapon(MC1);

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
	//DEFAULT playerINT("Default", "Default", 100);
	//DEFAULT * player1 = &playerINT;
	//DEFAULT * player2 = &playerINT;
//**********************************************	Mecha *player1 = NULL;
//**********************************************	Mecha *player2 = NULL;
	NEXT * player1 = &WG;
	Terminator * player2 = &T9;

	// Now we can do our main logic
	WG.display_stats();
	Ksh.display_stats();
	T9.display_stats();


	
	std::string player1input;
	std::string player2input;
	int count = 0;

	//allow user 1 to select a Mecha
/*	while (count == 0)
	{
		std::cout << "Player 1:  Select your Mecha." << std::endl;
		std::cout << "Type \" WG \" to select the White Glint Mecha." << std::endl;
		std::cout << "Type \" KSH \" to select the Kshatriya Mecha." << std::endl;
		std::cout << "Type \" T9 \" to select the T-9000 Terminator Mecha." << std::endl;
		std::cout << "Type \" exit \" to exit." << std::endl;
		std::getline(std::cin, player1input);
		if (player1input == " WG " || player1input == " wg " || player1input == "WG" || player1input == "wg")
		{
			//assign player1 to the White Glint Mecha
			NEXT * player1 = &WG;
			//player1 = (Mecha *)&WG;
			//player1 = (NEXT *)&WG;
			std::cout << "Player 1 is now White Glint Mecha" << std::endl;
			player1->display_stats();
			count++;
		}
		else if (player1input == " KSH " || player1input == " ksh " || player1input == "KSH" || player1input == "ksh")
		{
			//assign player1 to the Kshatriya Mecha
			MobileSuit * player1 = &Ksh;
			std::cout << "Player 1 is now Kshatriya Mecha" << std::endl;
			player1->display_stats();
			count++;
		}
		else if (player1input == " T9 " || player1input == " t9 " || player1input == "t9" || player1input == "T9")
		{
			//assign player1 to the T-9000 Terminator Mecha
			Terminator * player1 = &T9;
			std::cout << "Player 1 is now T-9000 Terminator Mecha" << std::endl;
			player1->display_stats();
			count++;
		}
		else if (player1input == " exit " || player1input == "exit" || player1input == " Exit " || player1input == "Exit")
		{
			count++;
			return 0;
		}
		else
		{
			std::cout << "ERROR:  Invalid response for Player 1.  Please try again." << std::endl;
		}
	}

	count = 0;

	//allow user 2 to select a Mecha
	while (count == 0)
	{
		std::cout << "Player 2:  Select your Mecha." << std::endl;
		std::cout << "Type \" WG \" to select the White Glint Mecha." << std::endl;
		std::cout << "Type \" KSH \" to select the Kshatriya Mecha." << std::endl;
		std::cout << "Type \" T9 \" to select the T-9000 Terminator Mecha." << std::endl;
		std::cout << "Type \" exit \" to exit." << std::endl;
		std::getline(std::cin, player2input);
		if (player2input == " WG " || player2input == " wg " || player2input == "WG" || player2input == "wg")
		{
			//assign player2 to the White Glint Mecha
			NEXT * player2 = &WG;
			//player2 = (NEXT *)&WG;
			std::cout << "Player 2 is now White Glint Mecha" << std::endl;
			player2->display_stats();
			count++;
		}
		else if (player2input == " KSH " || player2input == " ksh " || player2input == "KSH" || player2input == "ksh")
		{
			//assign player2 to the Kshatriya Mecha
			MobileSuit * player2 = &Ksh;
			std::cout << "Player 2 is now Kshatriya Mecha" << std::endl;
			player2->display_stats();
			count++;
		}
		else if (player2input == " T9 " || player2input == " t9 " || player2input == "t9" || player2input == "T9")
		{
			//assign player2 to the T-9000 Terminator Mecha
			Terminator * player2 = &T9;
			std::cout << "Player 2 is now T-9000 Terminator Mecha" << std::endl;
			player2->display_stats();
			count++;
			
		}
		else if (player2input == " exit " || player2input == "exit" || player2input == " Exit " || player2input == "Exit")
		{
			count++;
			return 0;
		}
		else
		{
			std::cout << "ERROR:  Invalid response for Player 2.  Please try again." << std::endl;
		}
	}*/


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
			std::cout << "\nPlayer 1, please select from an option below: (type the number of the option)" << std::endl;
			std::cout << "1 - Use Left Hand Weapon" << std::endl;
			std::cout << "2 - Use Right Hand Weapon" << std::endl;
			std::cout << "3 - Use Left Back Weapon" << std::endl;
			std::cout << "4 - Use Right Back Weapon" << std::endl;
			std::cout << "5 - Print Current Mech Stats" << std::endl;
			std::cout << "6 - End player turn early" << std::endl;

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
				std::cout << "Invalid Input, please try again" << std::endl;
			}


			switch (menuSelection)
			{
			case 1: //Select Left Hand Weapon
			{
				if (player1->getPWR() < player1->leftHandCost())	//prevent actions if user runs out of power
				{
					std::cout << "ERROR:  Not enough power available to use this weapon." << std::endl;
					break;
				}
				//std::cout << "Left Hand Weapon:  " << player1->set_leftHand_weapon << player1.
				//player1.//use player1.weaponA (apply cost to player1)
				//implement damage/hit points (apply damage to other player)
				std::cout << "\n\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
				player1->get_leftHand_weapon();  // displays which weapon was selected
				std::cout << "\nPlayer 1 Before Attack:  ";
				player1->printPWR();  // displays current power
				player1->drawPWR(player1->leftHandCost());  //calculates power draw 
				std::cout << "\nPlayer 1 After Attack:  ";
				player1->printPWR();
				std::cout << "\n-----------------------------------------------------------------" << std::endl;
				std::cout << "\nPlayer 2 Before Attack:  ";
				player2->getHP(); //displays remaing health for enemy
				player2->computeDamageReceived(player1->leftHandDMG());
				std::cout << "\nPlayer 2 After Attack:  ";
				player2->getHP();
				std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n" << std::endl;
				break;
			}

			case 2: // Select Right Hand Weapon
			{
				if (player1->getPWR() < player1->rightHandCost())	//prevent actions if user runs out of power
				{
					std::cout << "ERROR:  Not enough power available to use this weapon." << std::endl;
					break;
				}
				//use player1.weaponB (apply cost to player1)
				//implement damage/hit points (apply damage to other player)
				//player2->getHP(); //displays remaing health for enemy
				std::cout << "\n\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
				player1->get_rightHand_weapon();  // displays which weapon was selected
				std::cout << "\nPlayer 1 Before Attack:  ";
				player1->printPWR();  // displays current power
				player1->drawPWR(player1->rightHandCost());  //calculates power draw 
				std::cout << "\nPlayer 1 After Attack:  ";
				player1->printPWR();
				std::cout << "\n-----------------------------------------------------------------" << std::endl;
				std::cout << "\nPlayer 2 Before Attack:  ";
				player2->getHP(); //displays remaing health for enemy
				player2->computeDamageReceived(player1->rightHandDMG());
				std::cout << "\nPlayer 2 After Attack:  ";
				player2->getHP();
				std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n" << std::endl;
				break;
			}
			case 3: //Select Left Back Weapon
			{
				if (player1->getPWR() < player1->leftBackCost())	//prevent actions if user runs out of power
				{
					std::cout << "ERROR:  Not enough power available to use this weapon." << std::endl;
					break;
				}
				//use player1.weaponB (apply cost to player1)
				//implement damage/hit points (apply damage to other player)
				//player2->getHP(); //displays remaing health for enemy
				std::cout << "\n\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
				player1->get_leftBack_weapon();  // displays which weapon was selected
				std::cout << "\nPlayer 1 Before Attack:  ";
				player1->printPWR();  // displays current power
				player1->drawPWR(player1->leftBackCost());  //calculates power draw 
				std::cout << "\nPlayer 1 After Attack:  ";
				player1->printPWR();
				std::cout << "\n-----------------------------------------------------------------" << std::endl;
				std::cout << "\nPlayer 2 Before Attack:  ";
				player2->getHP(); //displays remaing health for enemy
				player2->computeDamageReceived(player1->leftBackDMG());
				std::cout << "\nPlayer 2 After Attack:  ";
				player2->getHP();
				std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n" << std::endl;
				break;
			}
			case 4: //Select Right Back Weapon
			{
				if (player1->getPWR() < player1->rightBackCost())	//prevent actions if user runs out of power
				{
					std::cout << "ERROR:  Not enough power available to use this weapon." << std::endl;
					break;
				}
				//use player1.weaponB (apply cost to player1)
				//implement damage/hit points (apply damage to other player)
				//player2->getHP(); //displays remaing health for enemy
				std::cout << "\n\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
				player1->get_rightBack_weapon();  // displays which weapon was selected
				std::cout << "\nPlayer 1 Before Attack:  ";
				player1->printPWR();  // displays current power
				player1->drawPWR(player1->rightBackCost());  //calculates power draw 
				std::cout << "\nPlayer 1 After Attack:  ";
				player1->printPWR();
				std::cout << "\n-----------------------------------------------------------------" << std::endl;
				std::cout << "\nPlayer 2 Before Attack:  ";
				player2->getHP(); //displays remaing health for enemy
				player2->computeDamageReceived(player1->rightBackDMG());
				std::cout << "\nPlayer 2 After Attack:  ";
				player2->getHP();
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
				std::cout << "Player 1 has chosen to end their turn." << std::endl;
				player1->drawPWR(1000);
				break;
			}
			}
		}

		if (player1->computeHP() >= 1 && player2->computeHP() <= 0)
		{
			//player1 wins
			std::cout << "\n\n+*+*+*+*+*+*+*+*+*+*+" << std::endl;
			std::cout << "|                   |" << std::endl;
			std::cout << "|  Player 1 WINs!!  |" << std::endl;
			std::cout << "|                   |" << std::endl;
			std::cout << "+*+*+*+*+*+*+*+*+*+*+\n\n" << std::endl;
			break;
		}
		if (player1->computeHP() <= 0 && player2->computeHP() >= 1)
		{
			//player2 wins
			std::cout << "\n\n+*+*+*+*+*+*+*+*+*+*+" << std::endl;
			std::cout << "|                   |" << std::endl;
			std::cout << "|  Player 2 WINs!!  |" << std::endl;
			std::cout << "|                   |" << std::endl;
			std::cout << "+*+*+*+*+*+*+*+*+*+*+\n\n" << std::endl;
			break;
		}
		
		while (player2->getPWR() >= 1)	//prevent actions if user runs out of power
		{
			//prints player menu
			std::cout << "\nPlayer 2, please select from an option below: (type the number of the option)" << std::endl;
			std::cout << "1 - Use Left Hand Weapon" << std::endl;
			std::cout << "2 - Use Right Hand Weapon" << std::endl;
			std::cout << "3 - Use Left Back Weapon" << std::endl;
			std::cout << "4 - Use Right Back Weapon" << std::endl;
			std::cout << "5 - Print Current Mech Stats" << std::endl;
			std::cout << "6 - End player turn early" << std::endl;

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
				std::cout << "Invalid Input, please try again" << std::endl;
			}


			switch (menuSelection)
			{
			case 1: //Select Left Hand Weapon
			{
				if (player2->getPWR() < player2->leftHandCost())	//prevent actions if user runs out of power
				{
					std::cout << "ERROR:  Not enough power available to use this weapon." << std::endl;
					break;
				}
				//std::cout << "Left Hand Weapon:  " << player2->set_leftHand_weapon << player2.
				//player2.//use player1.weaponA (apply cost to player1)
				//implement damage/hit points (apply damage to other player)
				std::cout << "\n\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
				player2->get_leftHand_weapon();  // displays which weapon was selected
				std::cout << "\nPlayer 2 Before Attack:  ";
				player2->printPWR();  // displays current power
				player2->drawPWR(player2->leftHandCost());  //calculates power draw 
				std::cout << "\nPlayer 2 After Attack:  ";
				player2->printPWR();
				std::cout << "\n-----------------------------------------------------------------" << std::endl;
				std::cout << "\nPlayer 1 Before Attack:  ";
				player1->getHP(); //displays remaing health for enemy
				player1->computeDamageReceived(player2->leftHandDMG());
				std::cout << "\nPlayer 1 After Attack:  ";
				player1->getHP();
				std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n" << std::endl;
				break;
			}

			case 2: // Select Right Hand Weapon
			{
				if (player2->getPWR() < player2->rightHandCost())	//prevent actions if user runs out of power
				{
					std::cout << "ERROR:  Not enough power available to use this weapon." << std::endl;
					break;
				}
				//use player1.weaponB (apply cost to player1)
				//implement damage/hit points (apply damage to other player)
				//player2->getHP(); //displays remaing health for enemy
				std::cout << "\n\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
				player2->get_rightHand_weapon();  // displays which weapon was selected
				std::cout << "\nPlayer 2 Before Attack:  ";
				player2->printPWR();  // displays current power
				player2->drawPWR(player2->rightHandCost());  //calculates power draw 
				std::cout << "\nPlayer 2 After Attack:  ";
				player2->printPWR();
				std::cout << "\n-----------------------------------------------------------------" << std::endl;
				std::cout << "\nPlayer 1 Before Attack:  ";
				player1->getHP(); //displays remaing health for enemy
				player1->computeDamageReceived(player2->rightHandDMG());
				std::cout << "\nPlayer 1 After Attack:  ";
				player1->getHP();
				std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n" << std::endl;
				break;
			}
			case 3: //Select Left Back Weapon
			{
				if (player2->getPWR() < player2->leftBackCost())	//prevent actions if user runs out of power
				{
					std::cout << "ERROR:  Not enough power available to use this weapon." << std::endl;
					break;
				}
				//use player1.weaponB (apply cost to player1)
				//implement damage/hit points (apply damage to other player)
				//player2->getHP(); //displays remaing health for enemy
				std::cout << "\n\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
				player2->get_leftBack_weapon();  // displays which weapon was selected
				std::cout << "\nPlayer 2 Before Attack:  ";
				player2->printPWR();  // displays current power
				player2->drawPWR(player2->leftBackCost());  //calculates power draw 
				std::cout << "\nPlayer 2 After Attack:  ";
				player2->printPWR();
				std::cout << "\n-----------------------------------------------------------------" << std::endl;
				std::cout << "\nPlayer 1 Before Attack:  ";
				player1->getHP(); //displays remaing health for enemy
				player1->computeDamageReceived(player2->leftBackDMG());
				std::cout << "\nPlayer 1 After Attack:  ";
				player1->getHP();
				std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n" << std::endl;
				break;
			}
			case 4: //Select Right Back Weapon
			{
				if (player2->getPWR() < player2->rightBackCost())	//prevent actions if user runs out of power
				{
					std::cout << "ERROR:  Not enough power available to use this weapon." << std::endl;
					break;
				}
				//use player1.weaponB (apply cost to player1)
				//implement damage/hit points (apply damage to other player)
				//player2->getHP(); //displays remaing health for enemy
				std::cout << "\n\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
				player2->get_rightBack_weapon();  // displays which weapon was selected
				std::cout << "\nPlayer 1 Before Attack:  ";
				player2->printPWR();  // displays current power
				player2->drawPWR(player2->rightBackCost());  //calculates power draw 
				std::cout << "\nPlayer 1 After Attack:  ";
				player2->printPWR();
				std::cout << "\n-----------------------------------------------------------------" << std::endl;
				std::cout << "\nPlayer 2 Before Attack:  ";
				player1->getHP(); //displays remaing health for enemy
				player1->computeDamageReceived(player2->rightBackDMG());
				std::cout << "\nPlayer 2 After Attack:  ";
				player1->getHP();
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
				std::cout << "Player 2 has chosen to end their turn." << std::endl;
				player2->drawPWR(1000);
				break;
			}
			}
		}
		if (player1->computeHP() >= 1 && player2->computeHP() <= 0)
		{
			//player1 wins
			std::cout << "\n\n+*+*+*+*+*+*+*+*+*+*+" << std::endl;
			std::cout << "|                   |" << std::endl;
			std::cout << "|  Player 1 WINs!!  |" << std::endl;
			std::cout << "|                   |" << std::endl;
			std::cout << "+*+*+*+*+*+*+*+*+*+*+\n\n" << std::endl;
			break;
		}
		if (player1->computeHP() <= 0 && player2->computeHP() >= 1)
		{
			//player2 wins
			std::cout << "\n\n+*+*+*+*+*+*+*+*+*+*+" << std::endl;
			std::cout << "|                   |" << std::endl;
			std::cout << "|  Player 2 WINs!!  |" << std::endl;
			std::cout << "|                   |" << std::endl;
			std::cout << "+*+*+*+*+*+*+*+*+*+*+\n\n" << std::endl;
			break;
		}

	}

	// This is where our game gets programmed
	// Have fun here 
	// Don't get stuck on requirments... just do it!

	getchar();
	getchar();

	return 0;
}