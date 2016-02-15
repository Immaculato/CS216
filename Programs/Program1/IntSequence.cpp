#include "IntSequence.h"
#include <cstdlib>
#include <iostream>
#include <iostream>
#include <algorithm>
#include <array>
#include <random>
#include <chrono>

using namespace std;

IntSequence::IntSequence()
{
	//make a new, empty int array with INITIAL_CAPACITY
	seq = new int[INITIAL_CAPACITY];
	capacity = INITIAL_CAPACITY;
	count = 0;
}

IntSequence::IntSequence(int in_capacity)
{
	//make a new, mepty int array with size in_capacity
	seq = new int[in_capacity];
	capacity = in_capacity;
	count = 0;
}

void IntSequence::insert(int item)
{
	//make a new temporary array with 1 greater size than the current array
	int* tempArray=new int[count+1];
	//for each element in the current array,
	for (int i=0; i < count; i++)
	{
		//swap over the value to the temporary array.
		tempArray[i] = seq[i];
	}
	//delete the current array,
	delete seq;
	//increment the size counter for the new element,
	count+=1;
	//actually insert the new item into the array, and finally,
	tempArray[count-1] = item;
	//make seq point to the new array.
	seq = tempArray;
}

void IntSequence::print()
{
	//for each item in seq, print it.
	for (int i=0; i<count; i++)
	{
		cout << seq[i] << " ";
	}
	//if there are no items to print, say so.
	if (count == 0)
	{
		cout << "Empty array! Read in some values.";
	}
	cout << endl;	

}

void IntSequence::selection_sort()
{
	cout << "===Selection Sort===================================\n";
	int minimum;
	int jmin;
	//for each item in the array,
	for (int i=0; i<count; i++)
	{
		//set the minimum to the first item in the subarray.
		minimum = seq[i];
		//for each item in the subarray,
		for (int j=i; j<count; j++)
		{
			//if a value is less than the minimum,
			if (seq[j] < minimum)
			{
				//make that value the new minimum,
				minimum = seq[j];
				//and make note of what index it happened at.
				jmin = j;
			}
		
		}
		//if the minimum wasn't the first item in the subarray,
		if (minimum != seq[i])
		{
		//say that you swapped it, and what with.
		cout << "Min " << minimum << ", swap with " << seq[i] << ":\t";
		}
		//if the first item in the subarray wasn't swapped,
		else
		{
		//say so.
		cout << "Min " << minimum << ", no swap:\t";
		}
		//if a smaller value was found,
		if (jmin != -1)
		{
			//swap the values of the minimum and first element.
			seq[jmin] = seq[i];
			seq[i]=minimum;
		}
		//print out the results, and reset jmin to keep sorting.
		print();
		jmin = -1;
	
		
	}
	//finally, output the sorted array.
	cout << "Sequence:\t\t";
	print();
}

void IntSequence::sort()
{
	//NOTE: this is functionally identical to the selection sort above,
	//but has no standard output. this method is used when the array must
	//be quietly sorted before the binary serach can be performed.
	int minimum;
	int jmin;
	for (int i=0; i<count; i++)
	{
		minimum = seq[i];
		for (int j=i; j<count; j++)
		{
			if (seq[j] < minimum)
			{
				minimum = seq[j];
				jmin = j;
			}
		
		}
		if (jmin != -1)
		{
			seq[jmin] = seq[i];
			seq[i]=minimum;
		}
		jmin = -1;
	}
}

void IntSequence::insertion_sort()
{
/*
func insertionsort( var A as an array of count n)
	for i= 1 to n - 1
		key = A[i]
		position = i
		while position > 0 and A[position-1] > key
			A[position] = A[position-1]
			position = position - 1
		end while
		A[position] = key
	end for
end func
*/
	cout << "===Insertion Sort===================================\n";
	int key;
	int position;
	//for the length of the list,
	for (int i=1; i<count; i++)
	{
		//the key is the current position's integer value, and
		key = seq[i];
		//the current position is the current index.
		position = i;
		//while the position is not and beginning, and the value behind is
		//greater than the value we're looking at,
		while (position > 0 && seq[position-1] > key)
		{
			//move the greater value one over.
			seq[position] = seq[position-1];
			//move back the position to check again.
			position = position - 1;
		}
		//if the correct position is found, put it in and continue.
		seq[position] = key;
		cout << "Insert " << seq[position] << ":\t";
		print();
	}
	cout << "Sequence:\t";
	print();
}

void IntSequence::bubble_sort()
{
/*
func BubbleSort( var a as an array of count n )
	for i from 1 to n-1
		for j from 0 to n-2
			if (a[j] > a[j+1])
				swap(a[j], a[j+1])
		end for
	end for
end func
*/
	cout << "===Bubble Sort===================================\n";
	int counter = 0;
	//for each element in the array, and
	for (int i=0; i < count; i++)
	{
		//for each element before the end,
		for (int j=0; j<count-1; j++)
		{
			//if the current element is greater than the next one,
			if (seq[j] > seq[j+1])
			{
				//swap the values,
				int tempvalue;
				tempvalue = seq[j];
				seq[j] = seq[j+1];
				seq[j+1] = tempvalue;
				//Increment the counter,
				counter+=1;
				//output the iteration number.
				cout << "Iteration " << counter << ":\t";
				print();
			}
		}
	}
	cout << "Sequence:\t";
	print();
}

void IntSequence::shuffle()
{
	//seed with the current time.
	srand(time(0));
	for (int i = 0; i < count; i++)
    	{
        	//Pick a random index from 0 to i
        	int j = rand() % (i+1);
 
        	//Swap seq[i] with the element at random index
        	swap(seq[i], seq[j]);
    	}
}

void IntSequence::sequential_search(int key)
{
	bool found = false;
	int location;
	int i=0;
	//while the key hasn't been found and all values have not been exhausted,
	while (found == false && i < count)
	{
		//if the key is found,
		if (key == seq[i])
		{
			//mark the location, and report that it's found.
			location = i;
			found = true;
		}
		i++;
	}
	//if the value was found,
	if (found)
	{
		//say so, and where.
		cout << "Key found at index " << location << endl;
		
	}
	//if it wasn't found,
	else
	{
		//report so.
		cout << "Key not found." << endl;
	}
	cout << "Search with " << i << " comparison(s)." << endl;
}


void IntSequence::binary_search(int key)
{
	int higher = count-1;
	int lower = 0;
	int middle;
	int location;
	int counter = 0;
	bool isitdone = false;
	while (isitdone == false)
	{
	if (higher < lower)
	{
		// set is empty, so return value showing not found
		isitdone = true;
		location = -1;
	}		
	else
	{
		// calculate midpoint to cut set in half
		middle = ((higher + lower)/2);

		if (seq[middle] > key)	//if the value in the middle is after the key,
		{
			//make 1 less than the middle the new max, and search again.
			higher = middle-1;
		}
		else if (seq[middle] < key)  //if the value in the middle is before the key,
		{
			//make 1 more than the middle the new lower index.
			lower = middle+1;
		}
		else     //if the value in the middle equals the word,
		{
			location = middle;
			isitdone = true;  //you've found it!!
		}
	}
	counter+=1;
	}
	//if the value was found,
	if (location != -1)
	{
		//say so.
		cout << "Key found at index " << location << endl;
	
	}
	//if it wasn't
	else
	{
		//say so.
		cout << "Key not found." << endl;
	}
	//report how long it took, too.
	cout << "Search with " << counter << " comparison(s)." << endl;
}


IntSequence::~IntSequence()
{
	delete seq;
}


