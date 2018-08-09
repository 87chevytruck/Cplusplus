/*
Ricky Smith
9 Aug 2018

BONUS LAB: CPP_CRYPTOGRAHAM CRACKER

objective: Design a CPP program that will encode user input.

requirements: print user input as both plain text and CODED. output to FILE!. alpha numeric only (a-z, A-Z, 0-9)

*/

#include <string>
#include <fstream>
#include <iostream>
#include <sstream>


int main()
{
	//***** Declare Strings *****
	std::string plainText;
	std::string codedText;
	std::string plainText2;
	std::string codedText2;

	//***** opens file for input into the program from the file *****
	std::ifstream messageFile("Coded-Secret-Message.txt");

	//***** checs that file is open, and if it is, inputs the file contents into a new string called codedText2 *****
	if (messageFile.is_open())
	{

		messageFile >> codedText2;
	}
	else
	{
		std::cout << "File not opened" << std::endl;

	}

	//***** closes file *****
	messageFile.close();

	//***** prints what the file's contents were by printsing the new string codedText 2 *****
	std::cout << "Your coded text message is:" << std::endl << codedText2 << std::endl;

	//***** prints line separator for visibility purposes *****
	std::cout << "\n\n*******    Decoded Text    ********" << std::endl;

	//***** makes both strings equal *****
	plainText2 = codedText2;

	//***** start FOR loop to iterate through the size of string, changes each element by adusting the element by +13 to encode, -13 to decode *****
	for (size_t i = 0; i < plainText2.size(); i++)
	{
		plainText2[i] = plainText2[i] - 13;

	}

	//***** prints out the decoded string *****
	std::cout << plainText2 << std::endl;
	


	while (1);
	return 0;
}