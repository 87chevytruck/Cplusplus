/*
Ricky Smith
7 Aug 2018

Practice:

Using what you know from C/C++ so far, create a quick program that accomplishes the following:
	Create a UI to accomplish all functionality
	Allow a user to input a person and their associated job title
	Allow a user to find a person based on name
		Allow a user to delete this person
	Allow the user to input more peopleomplish all functionality
	Allow a user to input a person and their associated job title
	Allow a user to find a person based on name
		Allow a user to delete this person
	Allow the user to input more people

*/

#include <iostream>
#include <map>
#include <string>
#include <sstream>



int printMap(std::map<std::string, std::string> employees);

int main(void)
{
	std::string name;
	std::string title;
	std::string input;
	int userInput = 0;
	std::map<std::string, std::string> employees;
	std::map<std::string, std::string>::iterator findEmployee;

	do
	{
		std::cout << "Select an option:" << std::endl;
		std::cout << "1 - Input Employee Name and Job Title" << std::endl;
		std::cout << "2 - Find Employee" << std::endl;
		std::cout << "3 - Delete Employee" << std::endl;
		std::cout << "4 - Print Employee Roster" << std::endl;
		std::cout << "0 - Exit" << std::endl;

		std::getline(std::cin, input);
		std::stringstream myStream(input);
		if (myStream >> userInput)
		{
			switch (userInput)
			{
			case 1:
				std::cout << "Enter Name" << std::endl;
			
				std::getline(std::cin, name);

				std::cout << "Enter Job Title" << std::endl;
			
				std::getline(std::cin, title);

				employees.emplace(name, title);
				std::cout << std::endl;
				printMap(employees);
				break;

			case 2:
				std::cout << "Enter Employee's name to find:  " << std::endl;
				std::getline(std::cin, name);
				findEmployee = employees.find(name);
				if (findEmployee == employees.end())
				{
					std::cout << "Employee not found";
				}
				else
				{
					std::cout << name << "Employee found" << std::endl;
					std::cout << "Do you wish to terminate employee? (Y/N)" << std::endl;
					std::getline(std::cin, input);
					if (input[0] == 'Y' || input[0] == 'y')
					{
						employees.erase(findEmployee);
						std::cout << name << " terminated!" << std::endl;
					}
					else
					{
						std::cout << name << " was saved!" << std::endl;
					}
				}
				break;

			case 3:
				printMap(employees);
				std::cout << std::endl;
				std::cout << "Which person do you want to destroy?" << std::endl;
				std::getline(std::cin, name);
				if (findEmployee == employees.end())
				{
					std::cout << "Employee not found" << std::endl;
				}
				else
				{
					employees.erase(findEmployee);
					std::cout << name << " has been destroyed!" << std::endl;
				}
				findEmployee = employees.find(name);
				break;

			case 4:
				printMap(employees);
				break;

			default:
				break;

			}
		}


	}


	while (1);
	return 0;
}

int printMap(std::map<std::string, std::string> employees)
{
	std::cout << "Employee Roster:" << std::endl;

	for (auto i = employees.cbegin(); i != employees.cend(); ++i)
	{
		std::cout << "Name:  " << i->first << "\tJob Title:  " << i->second << std::endl;
	}

	std::cout << "\n" << "\n";

	return 0;
}
