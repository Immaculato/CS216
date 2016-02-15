#include "IntSequence.cpp"
#include <cstdlib>
#include <string>
#include <iostream>
#include <algorithm>   
#include <array>        
#include <random>       
#include <chrono>

using namespace std;

int main();

int main()
{
	IntSequence listofnumbers;
	char choice;
	string line;
	bool breakflag;
	do
	{
	   cout << "=================================================" << endl;
	   cout << "1. Read\n2. Print\n3. Sort\n4. Shuffle\n5. Search\n6. Quit\nOption: ";
	   cin >> choice;
		//if the user wants to read in values,
		if (choice == '1')
		{
	 	 breakflag = false;
		 //while the user is providing values,
		 while (!breakflag)
		 {
			//keep reading lines from the file and inserting them.
			cout << "Enter the next element (Enter 'q' to stop): ";
			cin >> line;
			if (line != "q")
			{
				listofnumbers.insert(stoi(line));
			}
			//if they input q, stop taking in new values.
			else
			{
				breakflag=true;
			}
			
		 }
		}
		//if the user wants to print values,
		else if (choice == '2')
		{
		 //print them.
		 cout << "Sequence:\t";
		 listofnumbers.print();
		}
		//if the user wants to sort,
		else if (choice == '3')
		{
		 cout << "1. Insertion sort\n2. Selection sort\n3. Bubble sort\n4. Quit\nOption: ";
		 cin >> line;
		 //if the user wants to do an insertion sort,
		 if (line == "1")
		 {
			//do it.
			listofnumbers.insertion_sort();
		 }
		 //if the user wants to do a selection sort
		 else if (line == "2")
		 {
			listofnumbers.selection_sort();
		 }
		 //if the user wants to do a buble sort
		 else if (line == "3")
		 {
			listofnumbers.bubble_sort();
		 }
		 //if the user has no clue what they're doing,
		 else if (line != "4")
		 {
			//tell them.
			cout << "Invalid option." << endl;
		 }
		 //if they want to quit,
		 else
		 {
			//continue back to the main menu.
			continue;
		 }
		}
		//if the user wants to shuffle the values,
		else if (choice == '4')
		{
		 //shuffle them, and
		 listofnumbers.shuffle();
		 //display the new sequence.
		 cout << "Shuffled sequence:\t";
		 listofnumbers.print();
		}
		//if the user wants to search,
		else if (choice == '5')
		{
		 cout << "1. Sequential search\n2. Binary search \n3. Quit\nOption: ";
		 cin >> line;
		 //if the user wants to do a sequential search,
		 if (line == "1")
		 {
			//get a value to look for, and do it.
			cout << "Enter the key to find: ";
			int key;
			cin >> key;
		 	listofnumbers.sequential_search(key);
		 }
		 //if the user wants to do a binary search,
		 else if (line == "2")
		 {
			//get a value to look for,
			cout << "Enter the key to find: ";
                        int key;
                        cin >> key;
			cout << "Unsorted sequence: ";
			listofnumbers.print();
			//quietly sort the array, and
			cout << "Sorted sequence: ";
			listofnumbers.sort();
			listofnumbers.print();
			//do the binary search.
			listofnumbers.binary_search(key);
		 }
		 //if the user has no clue what they're doing,
		 else if (line != "3")
		 {
			//say so.
			cout << "Invalid option." << endl;
		 }
		 //otherwise,
		 else
		 {
			//go back to the main menu.
			continue;
		 }
		}
		//if the user has no idea what they're doing,
		else if (choice != '6')
		{
			//tell them.
			cout << "Invalid input." << endl;
		}

      } while(choice != '6'); //when the user has quit,
	//thank them for using the program and end it.
	cout << "Thank you for using this program." << endl;
	cout << "=================================================" << endl;		
}
