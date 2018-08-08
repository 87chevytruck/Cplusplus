/*
Ricky Smith
8 Aug 2018

Lab 2A

Provided a text file, use the STL to read from it and count each occurrence of each word. 
Once complete, output to **stdout **each word, and the number of times it occurred. 
Sort the output by words that occured the most to words that occured the least.
You will write this program in its entirety. 
There will be no source code provided by the instructor, only a text file containing the input.
The instructional goal of this lab is to give you practice using the STL. Use STL containers, algorithms, and iterators where they would be helpful.

*/

#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>


void printFrequency(std::string data);

int main()
{
	//***** declarations *****
	std::ifstream file("lyrics.txt");  //assigns file to a specifice file/document and opens it
	std::string line;  //used to get data from file line by line, temporarily storing that data as line
	std::string fileData;  //used to store entire file as one long string (no new lines)

	if (file.is_open())
	{
		std::cout << "\n******* \t Print data copied to string line via getline (displays as original file does) \t *******\n\n";

		while (std::getline(file, line))  //runs line by line through the text file, and temporarily asigns each line to the string "line"
		{
			fileData.append(line);  //stores the first "line" into fileData, then appends all other lines as the while loop continues
			fileData.append(" ");  //appends a space after each "line" as to cause a break between lines
		
			std::cout << line << std::endl;  //prints out each "line" as it loops through
		}

		file.close();  //closes file
	}
	else
	{
		std::cout << "Unable to open file…";
	}

	std::cout << "\n\n\n******* \t Print string fileData (all data from file copied to fileData string)\t  *******\n\n";

	std::cout << fileData << std::endl;  //prints out fileData string, one long string of the original file's data

	printFrequency(fileData);  //runs printFrequency function on the string fileData

	while (1);
	return 0;
}


//***** uses map and vector to separate, print, sort, and reprint individual words and counts *****
void printFrequency(std::string data)
{
	// each word it mapped to it's frequency
	std::map<std::string, int> FW;  //declares/creates map FW
	std::stringstream ss(data); // Used for breaking words
	std::string Word; // To store individual words

	while (ss >> Word)
		FW[Word]++;  //iterates

	std::map<std::string, int>::iterator m; //names m as the map iterator

	std::cout << "\n\n\n*******\t  Print Map WITHOUT Sorting\t  *******\n\n";

	for (m = FW.begin(); m != FW.end(); m++)  //FOR loop to iterate between the begining of the map FW and the end (m is the word)
		std::cout << m->first << " -> "  //prints the word
		<< m->second << "\n";  //prints the iterator count


	std::cout << "\n\n******* \t Print Map WITH Sorting \t *******\n\n";


	//sort the results: the first loop determines the most frequent map entry
	std::vector<std::pair<int, std::string> > sortMe;
	for (auto it = FW.cbegin(); it != FW.end(); it++)
	{
		sortMe.emplace_back(make_pair(it->second, it->first));  //pairs the two entries together so sorting by numbers, the word stays with its number
	}
	std::sort(sortMe.rbegin(), sortMe.rend()); //runs sort algorithm

	for (auto it = sortMe.cbegin(); it != sortMe.cend(); it++)
	{
		std::cout << it->second << " -> " << it->first << std::endl;  //prints word and iterator count
	}

}
