/*
Ricky Smith
7 Aug 2018

CPP 2.2 Practice Lab

Practice:

Using what you know from C/C++ so far, create a quick program that accomplishes the following:
	Create a UI to accomplish all functionality
	Allow a user to input a series of numbers, which are stored into a vector
	Create functions to add and subtract all numbers within the vector... from lowest index to highest
	Ensure value type is signed (for negative numbers)
	Allow a user to delete the last element
	Allow a user to clear the entire vector
		BONUS
			Allow a user to insert a new element at the back of vector
			Allow a user to insert, at a specific element, an additonal number
			Allow a user to delete a specific element
			etc

*/
#include <string>
#include <iostream>
#include <vector>
#include <sstream>


#define _CRT_SECURE_NO_WARNINGS 1


//****** functions declared *******
void print_vector(const std::vector<int> &userNumbers);
int input_numbers(void);
int add(std::vector<int> &userNumbers);
int subtract(std::vector<int> &userNumbers);

int main()
{
	//****** declarations ******
		int menuSelection = 99;
		std::vector <int> userNumbers;
		int insertElement2 = 0;
		int insertNumber = 0;
		int insertElement = 0;
		int addNumber = 0;
		std::string input2;


		//***** starts while loop for switch *****
		while (menuSelection != 0)
		{
			//***** prints selection menu *****
			std::cout << "Please select an option below:  " << std::endl;
			std::cout << "1 - Input Numbers\n2 - Add Vector Numbers\n3 - Subtract Vector Numbers\n4 - Delete Last Element\n5 - Clear Vector\n6 - Insert New Element At Back Of Vector\n7 - Insert At Specific Element\n8 - Delete Specific Element\n9 - Print Vector\n0 - Exit Program\n\n";
			

			//***** uses while loop to grab user selection, responds back invalad if selection is incorrect *****
			while (1)
			{
				std::getline(std::cin, input2);
				std::stringstream myStream(input2);
				if (myStream >> menuSelection)
				{
					break;
				}
				std::cout << "Invalid number, please try again" << std::endl;
			}

				//***** start switch/case *****
				switch (menuSelection)
				{
					case 1:
					{
						//***** gets vector numbers from user *****
						std::cout << "Please enter a list of numbers seperated by spaces to add to the vector: " << std::endl;

						std::string input;  // initialize string for std::cin
						std::getline(std::cin, input);  // get line from std::cin into input
						std::stringstream stream(input);  // make string stream

						while (1)
						{
							int n;
							stream >> n;
							if (!stream)
								break;
							userNumbers.emplace_back(n);  // Add number to end of vector
						}

						std::cout << std::endl;  // adds new line.
						std::cout << "Your vector numbers are:  ";
						print_vector(userNumbers);  // call print function to display vector numbers
						break;
					}
					case 2:
					{
						//***** runs add function *****
						add(userNumbers);
						break;
					}
					case 3:
					{
						//***** runs subtract function *****
						subtract(userNumbers);
						break;
					}
					case 4:
					{
						//***** deletes last element *****
						std::cout << "Current Vector numbers are:  " << std::endl;
						print_vector(userNumbers);  // call print function to display vector numbers

						userNumbers.pop_back();  //removes end element

						std::cout << "Vector numbers after last element deletion:  " << std::endl;
						print_vector(userNumbers);  // call print function to display vector numbers
						break;
					}
					case 5:
					{
						//***** Clear Vector *****
						std::cout << "Current Vector numbers are:  " << std::endl;
						print_vector(userNumbers);  // call print function to display vector numbers

						userNumbers.clear();  //clears/empties entire vector

						if (userNumbers.empty())  //checks if vector is empty
						{
							std::cout << "Vector has been emptied." << std::endl;
						}
						else
						{
							std::cout << "ERROR:  Vector was not emptied, please check code." << std::endl;
						}
						break;
					}
					case 6:
					{
						//***** Insert new element at back of vector *****
		
						std::cout << "Enter a number to add to the end of the vector." << std::endl;
						scanf("%d", &addNumber);
						std::cout << "Current Vector numbers are:  " << std::endl;
						print_vector(userNumbers);  // call print function to display vector numbers

						userNumbers.emplace_back(addNumber);  //adds number to the back of vector

						std::cout << "New Vector numbers are now:  " << std::endl;
						print_vector(userNumbers);  // call print function to display vector numbers
						break;
					}
					case 7:
					{
						//***** Insert at a specific element *****

						std::cout << "Enter a number you would like inserted into the vector." << std::endl;
						scanf("%d", &insertNumber);
						std::cout << "Enter the element number of the data you wish to replace with previous number you input." << std::endl;
						scanf("%d", &insertElement);
						insertElement = insertElement - 1;  //adjust user's input to minus 1 to take into account userNumbers.begin() below on line 168

						std::cout << "Current Vector numbers are:  " << std::endl;
						print_vector(userNumbers);  // call print function to display vector numbers

						userNumbers.emplace(userNumbers.begin() + insertElement, insertNumber);  //inserts user's number into specific position in vector

						std::cout << "Vector numbers after specific element insert are:  " << std::endl;
						print_vector(userNumbers);  // call print function to display vector numbers
						break;
					}
					case 8:
					{
						//***** delete specific element *****


						std::cout << "Enter the element number of the data you wish to remove." << std::endl;
						scanf("%d", &insertElement2);
						insertElement2 = insertElement2 - 1;  //adjust user's input to minus 1 to take into account userNumbers.begin() below on line 186
						
						std::cout << "Current Vector numbers are:  " << std::endl;
						print_vector(userNumbers);  // call print function to display vector numbers

						userNumbers.erase(userNumbers.begin() + insertElement2);  //removes specific element
				
						std::cout << "The new vector after element removal is:  " << std::endl;
						print_vector(userNumbers);  // call print function to display vector numbers
						break;
					}
					case 9:
					{
						std::cout << "Your vector numbers are:  ";
						print_vector(userNumbers);  // call print function to display vector numbers
						break;
					}
					default:
						break;
				}
		}

	return 0;
}


//***** print function for displaying vector *****
void print_vector(const std::vector<int>& userNumbers)
{
	
	for (const auto& item : userNumbers) //uses's memory location of each item (element) in the vector to "go through vector"
	{
		std::cout << item << " "; //prints out vector elements and add a space after each item (element)
	}
	std::cout << "\n\n";

}


//***** add  *****
int add(std::vector<int> &userNumbers)
{

	int sum_of_userNumbers = 0;
	for (const auto& element : userNumbers)  //uses's memory location of each element in the vector to "go through vector"
	{
		sum_of_userNumbers += element;  //adds each element to the previous sum as the FOR loop continues
	}
	std::cout << "The sum of all numbers in vector (low to high index number) is:  " << sum_of_userNumbers << std::endl;
	return 0;
}

//***** subtract *****
int subtract(std::vector<int> &userNumbers)
{
	int diff_of_userNumbers = 0;
	for (const auto& element : userNumbers)  //uses's memory location of each element in the vector to "go through vector"
	{
		diff_of_userNumbers -= element;  //subtracts each element from the previous difference as the FOR loop continues
	}
	std::cout << "The difference of all numbers in vector (low to high index number) is:  " << diff_of_userNumbers << std::endl;
	return 0;
}
