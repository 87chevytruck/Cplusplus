/*
Ricky Smith
CPP 2.2 Practice Lab

Practice:

Let's create a short program that does the following:

	Print out "Hello World!"
	Print the length of the string
	Create a substring of "Hello World!" and make it only contain "Hello"
		Print that substring out
	Find the "r" in "Hello World!"
		Print out it's position
	On the "Hello" substring, append your name.
		Print out the substring

*/

#include <string>
#include <iostream>


int main()
{
	std::string string1("Hello World!");  //initialized string
	auto string1_Length = string1.length();  //aquired length of string1


	std::cout << "The phrase of string1 is:  " << string1 << std::endl;  //printed string1
	std::cout << "The length of string1 is:  " << string1_Length << std::endl;  //printed the length of string1

	auto substring1 = string1.substr(0, 6);  //created substring using starting and ending index numbers

	std::cout << "The substring1 is:  " << substring1 << std::endl;  //prints substring1

	auto rpos = string1.find("r");  //finds letter "r" in string1 and assigns that to rpos

	std::cout << "The letter 'r' is found starting here:  " << rpos << std::endl;  //prints the location of letter "r" using rpos

	std::string myName("Ricky Smith");  //creats string with my name in it

	std::cout << "The substring1 appended with my name is:  \n";  //prints line 

	substring1.append(myName); //appends my name to substring1
	
	std::cout << substring1 << std::endl;  //prints substring1 (includes the appendage as vaiable substring has now changed)

	while (1);
	return 0;
}