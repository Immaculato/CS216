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
	}
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
			}
		}
	}
}

void IntSequence::print()
{
	for (int i=0; i<count; i++)
	{
		cout << seq[i] << endl;
	}	
}

IntSequence::~IntSequence()
{
	delete seq;
}


