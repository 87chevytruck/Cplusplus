/*
Ricky Smith
10 Aug 2018

Lab 3A

- Inside of **person.h **design a class Person, that has private data members for first name, last name, age and gender.
- Implement public functions to get and set the values of these private data members (example: std::string getFname(), 
	void setName(std::string fName), as well as your constructor(s) and destructor.
- Inside of main.cpp, you will find the function, **generate_roster() **that you will need to write. This funciton will 
	recieve user input to populate an array of Person objects, with each person being an individual in the class roster. 
	Return the number of students recorded.
- You will also find a function called **log_roster(). **Write this function to print each user out to roster.txt.
- Compile person.h and roster.cpp into an executable to test your work.
- If you are lost, please reach out for help.

*/


#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include "person.h"

//using namespace IQT;

int log_roster(std::vector<Person>&, std::ofstream&);
int generate_roster(std::vector<Person>&);

int main()
{
	std::ofstream outfile("roster.txt");
	std::vector<Person> roster;

	int roster_size = generate_roster(roster);
	int logged_count = log_roster(roster, outfile);

	if (roster_size == logged_count)
		std::cout << "Roster logged successfully";
	else
		std::cout << "Roster size and logged count mismatch. Error!" << std::endl;

	roster.clear();

	while (1);
	return 0;

}
//Arguments: std::vector<person>& roster - reference a vector containing the list of students in the class
//           std::ofstream& - a reference to the ofstream outfile object you will write too 
//Returns:  int count of the number of records written out 
//Purpose: write out the logic
int log_roster(std::vector<Person>& roster, std::ofstream& outfile)
{
	int count = 0;
	while (!roster.empty())  //only runs when there is data in the vector roster
	{
		//pushes info from roster into the outfile in a single line, separating the objects by spaces  
		outfile << roster.back().getFname() << " " << roster.back().getLname() << " " << roster.back().getAge() << " " << roster.back().getGender() << std::endl;
		roster.pop_back();
	}

	count++;  //increase count
	return count;
}

//Arguments: std::vector<Person>& roster - a reference to a vector that will contain the students you input 
//Returns: int count of the number of records input 
//Purpose: receive input and load the vector 
int generate_roster(std::vector<Person>& roster)
{

	//***** Declarations *****
	std::string firstName;
	std::string lastName;
	int age = 0;
	std::string gender;
	std::string input;  //used for string to int conversion with:: stringstream myStream
	int count = 0;
	int exit = 0;  //used to continue to input students or not
	
	Person Student(firstName, lastName, age, gender);  //assigns the class Person with an object called Student, includes which objects Student will have in it (members)

	while (exit == 0)  //takes input from user for exit, if user types 0, loop continues.
	{
		std::cout << "Enter first name." << std::endl;  //prompts user for input
		std::getline(std::cin, firstName);  //gets input from user
		Student.setFname(firstName);  //sets First Name
	

		std::cout << "Enter last name." << std::endl;  //prompts user for input
		std::getline(std::cin, lastName);  //gets input from user
		Student.setLname(lastName);  //sets Last Name
	

		while (true)
		{
			std::cout << "Enter age." << std::endl;  //prompts user for input
			std::getline(std::cin, input);  //gets input from user
			std::stringstream myStream(input);  //converts string to int for age
			if (myStream >> age)
			{
				Student.setAge(age);  //sets age only if a valid input
			
				break;
			}
			std::cout << "ERROR:  Invalid input for Age." << std::endl;
		
		}

		std::cout << "Enter gender." << std::endl;  //prompts user for input
		std::getline(std::cin, gender);  //gets input from user
		Student.setGender(gender);  //sets gender


		//*****  Provides users to continue inputting students or exit program *****
		while (true)
		{
			std::cout << "If you would like to enter another person, type 0.  Otherwise, type another number to continue with program." << std::endl;  //prompts user for input
			std::getline(std::cin, input);  //gets input from user
			std::stringstream myStream(input);  //converts string to int for exit
			if (myStream >> exit)
			{
				break;  //breaks while loop
			}
			std::cout << "ERROR:  Invalid input." << std::endl;

		}

		roster.push_back(Student);  //pushes each new student to the end of the vector to allow room for new student at the top of roster
	}
		
	count++;

	return count;

}