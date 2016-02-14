/* Tristan Basil
 * CS 215, Fall 2015
 * Programming Assignment 4 
 * 12/6/2015
 *
 * Implementation of WordList class.
 */

#include "wordlist.h"
#include <fstream>
#include <string>

WordList::WordList()
{
	words.clear();
}

WordList::WordList(string filename)
{
	ifstream infile;				//open the file
	infile.open(filename.c_str());

	string line;
	while (getline(infile, line)) //while the file is still supplying valid lines,
	{
		words.push_back(line); //push back the pointer to the derived object to the array
	}
}


bool WordList::WordInList(string word)
{
	if (BinarySearch(word, 0, words.size()-1))   //if the word can be found in the vector of possible words,
	{
		return true;  //return true
	}
	else
	{
		return false; //otherwise, return false.
	}
}


//helper function that recursively finds a word in the list.
bool WordList::BinarySearch(string word, int lower, int higher)
{
	// test if array is empty
	if (higher < lower)
		// set is empty, so return value showing not found
			return false;
	else
	{
		// calculate midpoint to cut set in half
		int middle = ((higher + lower)/2);

		if (words[middle] > word)				//if the word in the middle is after the word,
		{
			return BinarySearch(word, lower, middle-1);   //make 1 less than the middle the new max, and search again.
		}
		else if (words[middle] < word)			//if the word in the middle is before the word,
		{
			return BinarySearch(word, middle+1, higher);	//make 1 more than the middle the new lower index.
		}
		else     //if the word in the middle equals the word,
		{
			return true;  //by golly, you've found it!!
		}
	}
}

int WordList::size()
{
	return words.size();  //return the size of the vector.
}

//we did it reddit