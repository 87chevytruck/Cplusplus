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

	return 0;

}
//Arguments: std::vector<person>& roster - reference a vector containing the list of students in the class
//           std::ofstream& - a reference to the ofstream outfile object you will write too 
//Returns:  int count of the number of records written out 
//Purpose: write out the logic
int log_roster(std::vector<Person>& roster, std::ofstream& outfile)
{

	return 90;
}

//Arguments: std::vector<Person>& roster - a reference to a vector that will contain the students you input 
//Returns: int count of the number of records input 
//Purpose: receive input and load the vector 
int generate_roster(std::vector<Person>& roster)
{
	Person Student;
	Student.setFname(firstName);
	Student.setLname();
	Student.setAge();
	Student.setGender();

	return 90;

}