/*
Ricky Smith
8 Aug 2018

Linked Lists Practice Lab (Forward_List)

Practice:

Using what you know from C/C++ so far, create a quick and simple print program that accomplishes the following:
Allows user to add characters to the list
Allows user to pop off a character
Print each of the characters on a new line
Do the same with a fordward_list
Attempt to use operator[] or at(), note the results.

*/

#include <iostream>
#include <forward_list> // Needed for forward lists
#include <sstream>
#include <string>

//***** global declarations *****
int printList(std::forward_list<char> charString);
std::forward_list<char> charString = { 'a', 'b', 'c' };

int main(void)
{
	//***** declarations *****
	char inputChar;
	char removeChar;
	std::string input;
	int userInput = 99;

	//***** Start While Loop for Switch *****
	while (userInput != 0)
	{
		//***** Print Menu *****
		std::cout << "Select an option:" << std::endl;
		std::cout << "1 - Input Char into front of List" << std::endl;
		std::cout << "2 - Pop Off Front Char" << std::endl;
		std::cout << "3 - Print Char List" << std::endl;
		std::cout << "4 - Remove Char from List" << std::endl;
		std::cout << "0 - Exit" << std::endl;
		std::cout << "\n\n";

		//***** get menu selection *****
		std::getline(std::cin, input);
		std::stringstream myStream(input);
		if (myStream >> userInput)
		{
			switch (userInput)
			{
			case 1:
				//***** takes input from user to add to current list *****
				std::cout << "Enter Character" << std::endl;

				std::cin >> inputChar;
				charString.push_front(inputChar);  //places user's input to the front of list

				std::cout << std::endl;
				break;

			case 2:
				//***** removes first element from list *****
				std::cout << "Pop off front char." << std::endl;
				charString.pop_front();  //removes front element

				break;
			case 3:
				//***** run print function *****
				printList(charString);
				break;
			case 4:
				//***** removes user specified char form list *****
				std::cout << "Enter Character to remove" << std::endl;

				std::cin >> removeChar;
				charString.remove(removeChar);  //finds and removes user input "removeChar" from the list

				std::cout << std::endl;
				break;

			}
		}


	}
	return 0;
}

//***** prints the list and separates the elements with a new line *****
int printList(std::forward_list<char> charString)
{

	std::cout << "Char list:" << std::endl;

	for (const auto& elem : charString)  //loops through memory location of each element of charString
	{
		std::cout << elem << '\n'; //adds new line after each element
	}

	std::cout << "\n" << "\n";

	return 0;
}