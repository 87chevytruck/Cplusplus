/*
Ricky Smith
8 Aug 2018

Linked Lists Practice Lab

Practice:

Using what you know from C/C++ so far, create a quick and simple print program that accomplishes the following:
	Allows user to add characters to the list
	Allows user to pop off a character
	Print each of the characters on a new line
Do the same with a fordward_list
Attempt to use operator[] or at(), note the results.

*/

#include <iostream>
#include <list> // Needed for lists
#include <sstream>
#include <string>


int main()
{
	std::list<char> abc = { 'a', 'b', 'c', 'x', 'y', 'z' };

	for (const auto& elem : abc)
	{
		std::cout << elem << " ";
	}
	std::cout << "\n";

	std::string inputChar;
	//std::string input;
	int inputElement = 0;

	std::cout << "Enter a character you'd like to put into the list" << std::endl;
	std::getline(std::cin, inputChar);

	std::cout << "Enter element location you wish to place input character." << std::endl;
	std::cin >> inputElement;

	inputElement = inputElement - 1;
	abc.emplace(abc.begin() + inputElement, inputChar);

	std::cout << "The new abc list is:  " << abc << std::endl;
	
	for (const auto& elem : abc)
	{
		std::cout << elem << "\n";
	}

	std::cout


	while (1);
	return 0;
}

