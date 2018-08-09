/*
Ricky Smith
9 Aug 2018

Ch2 Performance Lab 2A

Lab 2B: Towers of Hanoi

You are given a _struct disc, with an int variable. You are also given three stack<disc> towers, source, temp dest. _
Read in an int n from the user, and create n number of discs, with each one's int variable numbered [0 - n]. Load these in descending order to source.
Your goal is to move the discs from source to dest, noting that you cannot stack a larger number disc on top of a smaller number disc and you can only move the top disc of a tower.
I provided you the function Hanoi(). Try and think of an implementation of this function, and use the STL stack functions. When you are done, print the number of steps to solve to stdout.
Try your solution out with different values of n. Then try and determine the max number of discs.


*/

#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <chrono>
#include <thread>


int Setup(std::stack<int>& tower, int n);
void Hanoi(std::stack<int>& source, std::stack<int>& dest, std::stack<int>& temp, int n);
void display(std::stack<int> tower);
static int numMoves = 0;

//***** declares stacks for towers *****
std::stack<int> TowerA;
std::stack<int> TowerB;
std::stack<int> TowerC;

int main()
{


	int n = 0;      //Number of discs 

	std::cout << "Enter number of discs" << std::endl;

	std::cin >> n;  //uses user's input for number of discs

	std::cout << "Number of discs are:  " << n << std::endl;

	n = Setup(TowerA, n);  //number of discs is now equal to function setup of TowerA and n discs
	Hanoi(TowerA, TowerC, TowerB, n);  //runs Hanoi program on the three towers and number of discs
	
	
	std::cout << "Displaying contents of tower A: " << std::endl;
	display(TowerA);
	std::cout << "Displaying contents of tower B: " << std::endl;
	display(TowerB);
	std::cout << "Displaying contents of tower C: " << std::endl;
	display(TowerC);
	std::cout << "Number of steps to solve: " << numMoves << std::endl;
	


	while(1);
	return 0;

}

//Arguments: std::stack<int>& towerA - a stack container that will be setup with a number of discs 
//           int n - a number that represents the number of discs to load on to the tower stack
//Return     the number of discs that were loaded on to the tower 
//Functionality: Load a number of discs in ascending order on to the stack 
int Setup(std::stack<int>& tower, int n)
{
	for (int i = n; i > 0; i--)  //FOR loop that takes number of discs and iterates down until number of discs left are 0 
	{
		tower.emplace(i);  //adds disc to the tower using the disc number as it's "size"
	}

	//***** displays towers after initial setup *****
	std::cout << "TowerA--| ";
	display(TowerA);
	std::cout << "TowerB--| ";
	display(TowerB);
	std::cout << "TowerC--| ";
	display(TowerC);
	std::cout << "___________________________________\n";
	return n;
}

//Arguments: std::stack<int>& source - the tower that discs will be moved from
//           std::stack<int>& dest - the twoer that discs will be moved to 
//           std::stack<int>& temp - a tower that can hold discs 
//           int n - the number of discs on the source tower
//Return     none
//Functionality: Move a tower from source to another tower. 
void Hanoi(std::stack<int>& source, std::stack<int>& dest, std::stack<int>& temp, int n)
{
	if (n == 1)
	{
		dest.emplace(source.top());  //copies the top of source stack to top of dest stack
		source.pop();  //deletes top of source stack (previously copied to dest stack)
		
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
		
		numMoves++;  //counts number of moves

		//***** displays towers after each move *****
		std::cout << "TowerA--| ";
		display(TowerA);
		std::cout << "TowerB--| ";
		display(TowerB);
		std::cout << "TowerC--| ";
		display(TowerC);
		std::cout << "___________________________________\n";
		return;
		//std::cout << "Move disc " << n << " from " << source << " to " << dest << std::endl;
	}
	else
	{
		Hanoi(source, temp, dest, n - 1);  //rearanges order of arguments for hanoi to run against, uses number of discs minus 1
		dest.emplace(source.top());  //copies the top of source stack to top of dest stack
		source.pop();  //deletes top of source stack (previously copied to dest stack)
		
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
		
		numMoves++;  //counts number of moves
		//std::cout << "Move disc " << n << " from " << source << " to " << dest << std::endl;
		
		//***** displays towers after each move *****
		std::cout << "TowerA--| ";
		display(TowerA);
		std::cout << "TowerB--| ";
		display(TowerB);
		std::cout << "TowerC--| ";
		display(TowerC);
		std::cout << "___________________________________\n";
		Hanoi(temp, dest, source, n - 1);  //rearanges order of arguments for hanoi to run against, uses number of discs minus 1

	}

}

//Arguments: std::stack<int>& tower - a tower that has discs to dispay
//Return     none
//Functionality: Display the contents of a tower
void display(std::stack<int> tower)
{
	while (!tower.empty())  //runs while loop while the tower being displayed is NOT empty
	{
		std::cout << tower.top() << " ";  //prints top of tower followed by a space
		tower.pop();  //pops off top of tower (allows for printing the next discs when the loop runs again)
	}
	std::cout << std::endl;
}