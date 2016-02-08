#include "sortings.h"
#include "cstdlib"
#include "iostream"

using namespace std;

IntSequence::IntSequence()
{
	intArray = new int[INITIAL_CAPACITY];
	capacity = INITIAL_CAPACITY;
	size = 0;
}

IntSequence::IntSequence(in_capacity)
{
	intArray = new int[in_capacity];
	capacity = in_capacity;
	size = 0;
}

int IntSequence::IntSequence()
{
	return size;
}

void IntSequence::insert(int item)
{
	int* tempArray=new int[size+1];
	for (int i=0; i < size; i++)
	{
		tempArray[i] = intArray[i];
	}
	delete intArray;
	size+=1;
	tempArray[size-1] = item;
	intArray = tempArray;
}

void IntSequence::insertion_sort()
{
/*
func insertionsort( var A as an array of size n)
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
	for (int i=1; i<size; i++)
	{
		//the key is the current position's integer value, and
		key = intArray[i];
		//the current position is the current index.
		position = i;
		//while the position is not and beginning, and the value behind is
		//greater than the value we're looking at,
		while (position > 0 && intArray[position-1] > key)
		{
			//move the greater value one over.
			intArray[position] = intArray[position-1];
			//move back the position to check again.
			position = position - 1;
		}
		//if the correct position is found, put it in and continue.
		intArray[position] = key;
	}
}

void IntSequence::bubble_sort()
{
/*
func BubbleSort( var a as an array of size n )
	for i from 1 to n-1
		for j from 0 to n-2
			if (a[j] > a[j+1])
				swap(a[j], a[j+1])
		end for
	end for
end func
*/
	for (int i=0; i < size; i++)
	{
		for (int j=0; j<size-1; j++)
		{
			if (intArray[j] > intArray[j+1])
			{
				int tempvalue;
				tempvalue = intArray[j];
				intArray[j] = intArray[j+1];
				intArray[j+1] = tempvalue;
			}
		}
	}
}

void sortings::print()
{
	for (int i=0; i<size; i++)
	{
		cout << intArray[i] << endl;
	}	
}

sortings::~sortings()
{
	delete intArray;
}


