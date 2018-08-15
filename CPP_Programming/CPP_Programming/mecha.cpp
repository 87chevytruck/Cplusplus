
#include "mecha.h"
#include "mecha_subs.h"

int main() {
	// TODO: Create your weapons here. 
	// Don't over think this step... just create weapon objects. One weapon can be used on multiple mechs
	Weapon BFF1("051ANNR", "Rifle", 100, 20);
	Weapon BFF2("063ANAR", "Assault Rifle", 50, 10);
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
	WG.set_leftHand_weapon(BFF2);
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
	}


	

	//end the game if a player's mech hits <= 0
	/*		while (player1 HP >= 0 && player2 HP >= 0)
			{  
			
			//allow users to take turns attacking
			//----allow users to decide which weapon to use during the their turn
			//prevent actions if user runs out of power
			//allow user to end their turn regardless of how much power is left


					while (player1 PWR >= 0)
					{
						prints player menu
						get input
					
						{
						switch(input)
							case: 1 Select weapon A
								{
									use player1.weaponA (apply cost to player1)
									implement damage/hit points (apply damage to other player)
									player2->getHP(); //displays remaing health for enemy
								}
							case: 2 Select weapon B
								{
									use player1.weaponB (apply cost to player1)
									implement damage/hit points (apply damage to other player)
									player2->getHP(); //displays remaing health for enemy
								}
							case: 3 Select weapon C
								{
									use player1.weaponC (apply cost to player1)
									implement damage/hit points (apply damage to other player)
									player2->getHP(); //displays remaing health for enemy
								}
							case: 4 Select weapon D
								{
									use player1.weaponD (apply cost to player1)
									implement damage/hit points (apply damage to other player)
									player2->getHP(); //displays remaing health for enemy
								}
							case: 5 Print Current Mech Stats
								{
									player1.display_stats
									player1->getHP(); //displays remaing health for current player
								}
							case: 6 End turn early
								{
									break;
								}
						}				
					}

					while (player2 PWR >= 0)
					{
						prints player menu
						get input

						{
						switch(input)
							case: 1 Select weapon A
								{
									use player2.weaponA (apply cost to player1)
									implement damage/hit points (apply damage to other player)
									player1->getHP(); //displays remaing health for enemy
								}
							case: 2 Select weapon B
								{
									use player2.weaponB (apply cost to player1)
									implement damage/hit points (apply damage to other player)
									player1->getHP(); //displays remaing health for enemy
								}
							case: 3 Select weapon C
								{
									use player2.weaponC (apply cost to player1)
									implement damage/hit points (apply damage to other player)
									player1->getHP(); //displays remaing health for enemy
								}
							case: 4 Select weapon D
								{
									use player2.weaponD (apply cost to player1)
									implement damage/hit points (apply damage to other player)
									player1->getHP(); //displays remaing health for enemy
								}
							case: 5 Print Current Mech Stats
								{
									player2.display_stats
									player2->getHP(); //displays remaing health for current player
								}
							case: 6 End turn early
								{
									break;
								}
						}
					}
			}


			if(player1 HP >= 1 && player2 HP <= 0)
			{
				player1 wins
			}
			else if(playder1 HP <= 0 && player2 HP >= 1)
			{
				player2 wins
			}
			else
			{
				winner could not be determined
			}



	*/





	// This is where our game gets programmed
	// Have fun here 
	// Don't get stuck on requirments... just do it!

	getchar();
	getchar();

	return 0;
}