#ifndef SORTINGS_H
#define SORTINGS_H

#include <string>
using namespace std;

const int INITIAL_CAPACITY = 5;

class sortings
{
   public:
	sortings(); // create an integer array with capacity = INITIAL_CAPACITY
	sortings(int in_capacity); //create an integer array with capacity = in_capacity
	int getSize();  //return the size of the current array
	void insert(string item);  // insert the item into the appropriate position of the array and size increased by 1
	void print();  // display all the items in the array
        ~sortings();  // destructor

   private:
	int capacity;  // the capacity of the array
	int size;   // the number of string items in the array
	string *sequence; // The pointer points at the first item in the array
};

#endif
