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



class Person {
private:
	std::string firstName;
	std::string lastName;
	int age;
	std::string gender;

public:
	char setFname(std::string firstName)
	{
		std::getline(std::cin, firstName);
	}
	char setLname(std::string lastName)
	{
		std::getline(std::cin, lastName);
	}
	int setAge(int age)
	{
		std::cin >> age;
	}
	char setGender(std::string gender)
	{
		std::getline(std::cin, gender);
	}
};
