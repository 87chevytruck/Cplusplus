/*
Ricky Smith
8 Aug 2018

CPP 2.6 Practice Lab

Practice:

Using what you know from C/C++ so far, create a quick program that accomplishes the following:
	Feel free to reuse your vector practice code
	Create a UI to accomplish all functionality
	Allow a user to input a series of numbers, which are stored into a deque
	Create functions to add and subtract all numbers within the deque... from lowest index to highest
	Ensure value type is signed (for negative numbers)
	Allow a user to delete the first or last element
	Allow a user to clear the entire deque

	BONUS
		Allow a user to insert a new element at the front or back of the deque
		Allow a user to insert, at a specific element, an additonal number
		Allow a user to delete a specific element
		etc


*/
#include <string>
#include <iostream>
#include <deque>
#include <sstream>


#define _CRT_SECURE_NO_WARNINGS 1


//****** functions declared *******
void print_deque(const std::deque<int> &userNumbers);
int input_numbers(void);
int add(std::deque<int> &userNumbers);
int subtract(std::deque<int> &userNumbers);

int main()
{
	//****** declarations ******
	int menuSelection = 99;
	std::deque <int> userNumbers;
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
		std::cout << "1 - Input Numbers\n2 - Add Deque Numbers\n3 - Subtract Deque Numbers\n4 - Delete Last Element\n5 - Clear Deque\n6 - Insert New Element At Back Of Deque\n7 - Insert At Specific Element\n8 - Delete Specific Element\n9 - Print Deque\n0 - Exit Program\n\n";


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
			//***** gets Deque numbers from user *****
			//std::cin.clear();
			//system("cls");  // Clear screen to make it purdy
			std::cout << "Please enter a list of numbers seperated by spaces to add to the Deque: " << std::endl;

			std::string input;  // initialize string for std::cin
			std::getline(std::cin, input);  // get line from std::cin into input
			std::stringstream stream(input);  // make string stream

			while (1)
			{
				int n;
				stream >> n;
				if (!stream)
					break;
				userNumbers.emplace_back(n);  // Add number to end of Deque
			}

			std::cout << std::endl;  // adds new line.
			std::cout << "Your Deque numbers are:  ";
			print_deque(userNumbers);  // call print function to display Deque numbers
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
			std::cout << "Current Deque numbers are:  " << std::endl;
			print_deque(userNumbers);  // call print function to display Deque numbers

			userNumbers.pop_back();  //removes end element

			std::cout << "Deque numbers after last element deletion:  " << std::endl;
			print_deque(userNumbers);  // call print function to display Deque numbers
			break;
		}
		case 5:
		{
			//***** Clear Deque *****
			std::cout << "Current Deque numbers are:  " << std::endl;
			print_deque(userNumbers);  // call print function to display Deque numbers

			userNumbers.clear();  //clears/empties entire Deque

			if (userNumbers.empty())  //checks if Deque is empty
			{
				std::cout << "Deque has been emptied." << std::endl;
			}
			else
			{
				std::cout << "ERROR:  Deque was not emptied, please check code." << std::endl;
			}
			break;
		}
		case 6:
		{
			//***** Insert new element at back of Deque *****

			std::cout << "Enter a number to add to the end of the Deque." << std::endl;
			scanf("%d", &addNumber);
			std::cout << "Current Deque numbers are:  " << std::endl;
			print_deque(userNumbers);  // call print function to display Deque numbers

			userNumbers.emplace_back(addNumber);  //adds number to the back of Deque

			std::cout << "New Deque numbers are now:  " << std::endl;
			print_deque(userNumbers);  // call print function to display Deque numbers
			break;
		}
		case 7:
		{
			//***** Insert at a specific element *****

			std::cout << "Enter a number you would like inserted into the Deque." << std::endl;
			scanf("%d", &insertNumber);
			std::cout << "Enter the element number of the data you wish to replace with previous number you input." << std::endl;
			scanf("%d", &insertElement);
			insertElement = insertElement - 1;  //adjust user's input to minus 1 to take into account userNumbers.begin() below on line 168

			std::cout << "Current Deque numbers are:  " << std::endl;
			print_deque(userNumbers);  // call print function to display Deque numbers

			userNumbers.emplace(userNumbers.begin() + insertElement, insertNumber);  //inserts user's number into specific position in Deque

			std::cout << "Deque numbers after specific element insert are:  " << std::endl;
			print_deque(userNumbers);  // call print function to display Deque numbers
			break;
		}
		case 8:
		{
			//***** delete specific element *****


			std::cout << "Enter the element number of the data you wish to remove." << std::endl;
			scanf("%d", &insertElement2);
			insertElement2 = insertElement2 - 1;  //adjust user's input to minus 1 to take into account userNumbers.begin() below on line 186

			std::cout << "Current Deque numbers are:  " << std::endl;
			print_deque(userNumbers);  // call print function to display Deque numbers

			userNumbers.erase(userNumbers.begin() + insertElement2);  //removes specific element

			std::cout << "The new Deque after element removal is:  " << std::endl;
			print_deque(userNumbers);  // call print function to display Deque numbers
			break;
		}
		case 9:
		{
			std::cout << "Your Deque numbers are:  ";
			print_deque(userNumbers);  // call print function to display Deque numbers
			break;
		}
		default:
			break;
		}
	}

	return 0;
}


//***** print function for displaying vector *****
void print_deque(const std::deque<int>& userNumbers)
{

	for (const auto& item : userNumbers) //uses's memory location of each item (element) in the vector to "go through Deque"
	{
		std::cout << item << " "; //prints out Deque elements and add a space after each item (element)
	}
	std::cout << "\n\n";

}


//***** add  *****
int add(std::deque<int> &userNumbers)
{

	int sum_of_userNumbers = 0;
	for (const auto& element : userNumbers)  //uses's memory location of each element in the Deque to "go through Deque"
	{
		sum_of_userNumbers += element;  //adds each element to the previous sum as the FOR loop continues
	}
	std::cout << "The sum of all numbers in Deque (low to high index number) is:  " << sum_of_userNumbers << std::endl;
	return 0;
}

//***** subtract *****
int subtract(std::deque<int> &userNumbers)
{
	int diff_of_userNumbers = 0;
	for (const auto& element : userNumbers)  //uses's memory location of each element in the Deque to "go through Deque"
	{
		diff_of_userNumbers -= element;  //subtracts each element from the previous difference as the FOR loop continues
	}
	std::cout << "The difference of all numbers in Deque (low to high index number) is:  " << diff_of_userNumbers << std::endl;
	return 0;
}
