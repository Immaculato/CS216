#include "IntSequence.h"
#include <cstdlib>
#include <iostream>

using namespace std;

IntSequence::IntSequence()
{
	seq = new int[INITIAL_CAPACITY];
	capacity = INITIAL_CAPACITY;
	count = 0;
}

IntSequence::IntSequence(int in_capacity)
{
	seq = new int[in_capacity];
	capacity = in_capacity;
	count = 0;
}

int IntSequence::lower()
{
	return seq[0];
}

int IntSequence::higher()
{
	return seq[count-1];
}

void IntSequence::insert(int item)
{
	int* tempArray=new int[count+1];
	for (int i=0; i < count; i++)
	{
		tempArray[i] = seq[i];
	}
	delete seq;
	count+=1;
	tempArray[count-1] = item;
	seq = tempArray;
}

void IntSequence::print()
{
	for (int i=0; i<count; i++)
	{
		cout << seq[i] << " ";
	}
	cout << endl;	
}

void IntSequence::selection_sort()
{
	cout << "===Selection Sort===================================\n";
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
		if (minimum != seq[i])
		{
		cout << "Min " << minimum << ", swap with " << seq[i] << ":\t";
		}
		else
		{
		cout << "Min " << minimum << ", no swap:\t";
		}
		if (jmin != -1)
		{
			seq[jmin] = seq[i];
			seq[i]=minimum;
		}
		print();
		jmin = -1;
	
		
	}
	cout << "Sequence:\t\t";
	print();
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
	for (int i=0; i < count; i++)
	{
		for (int j=0; j<count-1; j++)
		{
			if (seq[j] > seq[j+1])
			{
				int tempvalue;
				tempvalue = seq[j];
				seq[j] = seq[j+1];
				seq[j+1] = tempvalue;
				counter+=1;
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
	cout << "implement this" << endl;
}

int IntSequence::sequential_search(int key)
{
	for (int i=0; i<count; i++)
	{
		if (key == seq[i])
		{
			return i;
		}
	}
	return -1;
}


int IntSequence::binary_search(int key, int lower, int higher)
{
	// test if array is empty
	if (higher < lower)
		// set is empty, so return value showing not found
			return -1;
	else
	{
		// calculate midpoint to cut set in half
		int middle = ((higher + lower)/2);

		if (seq[middle] > key)				//if the word in the middle is after the word,
		{
			return binary_search(key, lower, middle-1);   //make 1 less than the middle the new max, and search again.
		}
		else if (seq[middle] < key)			//if the word in the middle is before the word,
		{
			return binary_search(key, middle+1, higher);	//make 1 more than the middle the new lower index.
		}
		else     //if the word in the middle equals the word,
		{
			return middle;  //you've found it!!
		}
	}
}


IntSequence::~IntSequence()
{
	delete seq;
}


