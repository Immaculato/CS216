//Provide the function implementation 
//for the functions declared in lab7functions.h

#include "lab7functions.h"

int* func1(int &parm1,int parm2) 
{ 
	// function scope to stack storage
	cout << "Calling func1: " << endl;
	// function scope ptr in stack storage, it points to storage in the heap
	int *ptr = new int; 
	int temp = parm1;
	parm1 = (parm1 + parm2)/2;  
	if (temp > parm2)
		*ptr = temp - parm1;
	else 
		*ptr = parm2 - parm1; 
	// the potential of memory leak!!! it needs to be released from the caller.
	return ptr; 
} 

int func2(int count)
{ 
	// function scope to stack storage
	cout << "Calling func2: " << endl;
	// function scope but program storage
	static int sum = 0; 
	// sum retains its value between calls
	sum = sum + count;   // sum keeps value for next call
	return sum;
}

string* func3() {
	// function scope to stack storage
	cout << "Calling func3: " << endl;
	// Typical use of heap storage:
	// Allocate heap buffer for an array of strings
	string *sptr = new string[SIZE];
    	// block scope storage
	for (int num1 = 0; num1 < SIZE; num1++) {
		cout << "Please input string item " << num1 << ": "<< endl;
		getline(cin, sptr[num1]);
	}
	// No function or block declare,
	// num1 is global
	cout << "num1 after for loop: " << num1 << endl;
	// Heap storage must be freed
    	// when done with it
	// potential memory leak!!!
	return sptr;
} 

string change_Str(string original)
{
	cout << "Calling recursive functions: " << endl;
	if (original.length() <= 1)
		return original + original;
	string mid = change_Str(original.substr(1, original.length()-1));
	return original[0] + mid + original[0];
}

string reverse(string original, int& times)
{
	times++;
	if (original.length() == 0 || original.length() == 1)
	{
		return original;
	}
	return original[original.length()-1] + reverse(original.substr(0, original.length()-1), times);
}
