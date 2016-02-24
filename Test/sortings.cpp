#include "sortings.h"
#include <iostream>
#include <string>

using namespace std;

sortings::sortings()
{
	sequence = new string[INITIAL_CAPACITY];
	capacity = INITIAL_CAPACITY;
	size = 0;
}

sortings::sortings(int in_capacity)
{
	sequence = new string[in_capacity];
	capacity = in_capacity;
	size = 0;
}

int sortings::getSize()
{
	return size;
}

void sortings::insert(string item)
{ 
	if (size == 0)
	{
		sequence[0] = item;
		size++;
		return;
	}
	string* tempArray=new string[size+1];
	bool found = false;
        for (int i=0; i < size; i++)
        {
		if (item < sequence[i] && found == false)
		{
			tempArray[i] = item;
			found = true;
		}
		else if (found == false)
		{
               		tempArray[i] = sequence[i];
		}
		if (found == true)
		{
			tempArray[i+1] = sequence[i];
		}
        }
	if (found == false)
	{
		tempArray[size] = item;
	}
	delete[] sequence;
        size+=1;
	capacity=size;
        sequence = tempArray;
}

void sortings::print()
{
	cout << "Items in the array:" << endl;
	for (int i=0; i<size; i++)
	{
		cout << sequence[i] << endl;
	}
}

sortings::~sortings()
{
	delete[] sequence;
}
