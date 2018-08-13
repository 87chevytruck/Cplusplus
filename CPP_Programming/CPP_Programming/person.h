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
	//***** sets private members of class Person *****
private:
	std::string firstName;
	std::string lastName;
	int age;
	std::string gender;


	//***** sets public members of class Person *****
public:
	Person(std::string first, std::string last, int a, std::string gen)  //needed to declare Student as a class Person in the main cpp file
	{
		//***** Declarations used in functions *****
		firstName = first;
		lastName = last;
		age = a;
		gender = gen;
	}
	
	void setFname(std::string first)  //function to set first name, throws into Person above
	{
		firstName = first;
	}

	void setLname(std::string last)  //function to set last name, throws into Person above
	{
		lastName = last;
	}

	void setAge(int a)  //function to set age, throws into Person above
	{
		age = a;
	}

	void setGender(std::string gen)  //function to set gender, throws into Person above
	{
		gender = gen;
	}

	std::string getFname()  //set function to "grab" object from vector in main cpp file
	{
		return firstName;
	}

	std::string getLname()  //set function to "grab" object from vector in main cpp file
	{
		return lastName;
	}

	int getAge()  //set function to "grab" object from vector in main cpp file
	{
		return age;
	}

	std::string getGender()  //set function to "grab" object from vector in main cpp file
	{
		return gender;

	}

};
