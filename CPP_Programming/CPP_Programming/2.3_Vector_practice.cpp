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
		int menuSelection = 0;
		std::vector <int> userNumbers{ 0 };
		//std::vector <int> input;
		int insertElement2 = 0;
		int insertNumber = 0;
		int insertElement = 0;
		int addNumber = 0;
		//int element;
		//std::string input2;
		int input2;

		/*
		std::cout << "Please Enter a series of numbers, separated by spaces, end with a non-number character:  " << std::endl;

		while (std::cin >> element)
		{
			input.push_back(element);
		}

		std::cout << "This is your vector:  " << std::endl;
		print_vector(input);
		std::cout << "\n\n";
		*/

		do
		{

			std::cout << "Please select an option below:  " << std::endl;
			std::cout << "1 - Input Numbers\n2 - Add Vector Numbers\n3 - Subtract Vector Numbers\n4 - Delete Last Element\n5 - Clear Vector\n6 - Insert New Element At Back Of Vector\n7 - Insert At Specific Element\n8 - Delete Specific Element\n0 - Exit Program\n\n";
			std::cin >> input2;

				switch (input2)
				{
				case 1:
				{
					input_numbers();
					break;
				}
				case 2:
				{
					add(userNumbers);
					break;
				}
				case 3:
				{
					subtract(userNumbers);
					break;
				}
				case 4:
				{
					//*****deletes last element*****
					std::cout << "Vector before last element removal is:  " << &userNumbers << std::endl;
					userNumbers.back() = '\0';
					std::cout << "Vector without last element is now:  " << &userNumbers << std::endl;
					break;
				}
				case 5:
				{
					//*****Clear Vector*****
					std::cout << "Vector before clearing is:  " << &userNumbers << std::endl;
					userNumbers.clear();
					if (userNumbers.empty())
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
					//*****Insert new element at back of vector*****
					//int addNumber = 0;

					std::cout << "Enter a number to add to the end of the vector." << std::endl;
					scanf("%d", &addNumber);
					std::cout << "Current Vector numbers are:  " << &userNumbers << std::endl;
					userNumbers.emplace_back(addNumber);
					std::cout << "New Vector numbers are now:  " << &userNumbers << std::endl;
					break;
				}
				case 7:
				{
					//*****Insert at a specific element*****
					//int insertNumber = 0;
					//int insertElement = 0;

					std::cout << "Enter a number you would like inserted into the vector." << std::endl;
					scanf("%d", &insertNumber);
					std::cout << "Enter the element number of the data you wish to replace with previous number you input." << std::endl;
					scanf("%d", &insertElement);
					insertElement = insertElement - 1;
					std::cout << "The vector before inserting a new number is:  " << &userNumbers << std::endl;
					userNumbers.emplace(userNumbers.begin() + insertElement, insertNumber);
					std::cout << "The new vector after number insertion is:  " << &userNumbers << std::endl;
					break;
				}
				case 8:
				{
					//*****delete specific element*****
					//int insertElement2 = 0;

					std::cout << "Enter the element number of the data you wish to remove." << std::endl;
					scanf("%d", &insertElement2);
					insertElement2 = insertElement2 - 1;
					std::cout << "The vector before deleting a specific element was:  " << &userNumbers << std::endl;
					userNumbers.erase(userNumbers.begin() + insertElement2);
					std::cout << "The new vector after element removal is:  " << &userNumbers << std::endl;
					break;
				}
				default:
					break;
				}
		}
	while (input2 != 0);

	return 0;
}


//***** print function for displaying vector *****
void print_vector(const std::vector<int>& userNumbers)
{
	for (const auto& item : userNumbers)
	{
		std::cout << item << " ";
	}
	std::cout << "\n";

}


//***** inputs numbers into vector *****
int input_numbers(void)
{
	std::vector <int> input;
	int element;

	std::cout << "Please Enter a series of numbers, separated by spaces, end with a non-number character:  " << std::endl;

	while (std::cin >> element)
	{
		input.push_back(element);
	}

	std::cout << "This is your vector:  " << std::endl;
	print_vector(input);
	std::cout << "\n\n";
	
	return 0;
	/*
	int user_input = 0;
	char more_numbers = {};
	int count = 0;

	//check to see if this is the first number being input
	if (count == 0)
	{
		std::cout << "Please input your first number.\n" << std::endl;
		std::cin >> user_input;
		{
			userNumbers.emplace_back(user_input);
			count++;
		}
	
	//allow user to input additional numbers
	
		std::cout << "Please input another number.\n" << std::endl;
		std::cin >> user_input;
		{
			userNumbers.emplace_back(user_input);
			count++;
		}
	}
	//check to see if the user would like to input additional numbers
	std::cout << "Would you like to add another number? (Y/N)\n" << std::endl;
	std::cin >> more_numbers;
	//if the user wants to add additional numbers, call the function again
	if (more_numbers == 'Y' || more_numbers == 'y')
	{
		input_numbers(userNumbers);
	}
	//if the user doesn't want to add additional numbers, return to menu
	else if (more_numbers == 'N' || more_numbers == 'n')
	{
		return 1;
	}
	//error
	else
	{
		return -1;
	}
	return 1;
	*/
}

//***** add funciont *****
int add(std::vector<int> &userNumbers)
{

	int sum_of_userNumbers = 0;
	for (const auto& element : userNumbers)
	{
		sum_of_userNumbers += element;
	}
	std::cout << "The sum of all numbers in vector (low to high index number) is:  " << sum_of_userNumbers << std::endl;
	return 0;
}

//***** subtract *****
int subtract(std::vector<int> &userNumbers)
{
	int diff_of_userNumbers = 0;
	for (const auto& element : userNumbers)
	{
		diff_of_userNumbers -= element;
	}
	std::cout << "The difference of all numbers in vector (low to high index number) is:  " << diff_of_userNumbers << std::endl;
	return 0;
}
